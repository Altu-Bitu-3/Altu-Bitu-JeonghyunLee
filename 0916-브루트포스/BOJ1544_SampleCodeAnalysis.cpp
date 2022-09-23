#include<iostream> //c++ 입출력 헤더파일
#include<set> //set 사용 헤더파일
using namespace std; //std 클래스에 있는 함수들을 앞에 std 붙이지 않고 쓰겠다.

bool isCycle(set<string>& s, string str) { //사이클단어인지 아닌지 true/false로 리턴하는 함수
	int cnt = str.length(); //단어 길이 변수에 저장

	while (cnt--) { //단어 길이만큼 반복
		// 같은 단어가 있는 경우
		if (s.find(str) != s.end()) { //set에 주어진 단어가 없다면
			return true; //사이클 단어다
		}

		// 시계 방향대로, 앞 글자를 떼어서 뒤에 붙여줌.
		str = str + str[0]; //앞글자를 제일 뒤에 붙임
		str.erase(0, 1); //앞 글자 한 개 삭제
	}
	return false; //사이클 단어가 아니다
}
int main() { //메인 함수
	int n; //단어의 개수
	string str; //단어
	set<string> word; // 사이클 단어 저장

	// 입력
	cin >> n; //단어의 개수 입력 받음
	while (n--) { //n만큼 반복 (단어 n개)
		cin >> str; //단어 입력 받음

		// 같은 단어 없으면 추가
		if (!isCycle(word, str)) { //word안에 있는 단어의 사이클 단어가 아니라면
			word.insert(str); //word에 단어 저장
		}
	}

	// 출력
	cout << word.size(); //word의 크기 출력 (저장된 단어 개수 출력)
}