#include <iostream> //c++의 입출력을 위한 헤더파일
#include <set> //set 사용을 위한 헤더파일

using namespace std; //cin, cout 등을 사용할 때 앞에 std 적는 것 생략을 위해

string str; //문자열 str 변수를 전역변수로 선언
set<string> s; //string 원소들을 담은 set을 전역변수로 선언

void makeNum(int left, int right, string path) { //숫자 N 만드는 함수
	if (left == 0 && right == str.length() - 1) { // 더 이상 좌우로 이동할 곳이 없을 경우
		s.insert(path); //set에 만든 순서 추가
		return; //함수 종료
	}

	// 검사 범위 체크
	if (left > 0) { //왼쪽에 숫자 적기 가능
		makeNum(left - 1, right, path + str[left - 1] + path); // 왼쪽에 숫자를 하나 적는 과정
	}
	if (right < str.length() - 1) { //오른쪽에 숫자 적기 가능
		makeNum(left, right + 1, path + path + str[right + 1]); // 오른쪽에 숫자를 하나 적는 과정
	}
}
/*
* [N으로 만들기]
* - 어떤 수 N을 만들기 위해, 아래 두 가지 행동 반복
*	1. 수의 왼쪽에 숫자를 하나 적는다.
*	2. 수의 오른쪽에 숫자를 하나 적는다.
*
* - 숫자를 적는 과정에서 나온 수가 순서대로 모두 같다면 같은 방법이다.
* -> 숫자를 적는 과정을 string으로 연결하여 저장 후 set으로 중복 체크
*/
int main() { //메인함수
	// 입력
	cin >> str; //str 입력받기

	// 계산
	for (int i = 0; i < str.length(); i++) { //str의 글자수만큼 반복, i번째 숫자마다 makeNum 함수 실행
		string tmp = ""; //str[i]를 string 형태로 바꾸기 위해 tmp를 더함
		makeNum(i, i, tmp + str[i]); //숫자 N 만들기
	}

	// 출력
	cout << s.size(); //set s의 크기(숫자 N을 만드는 방법의 수) 출력
}