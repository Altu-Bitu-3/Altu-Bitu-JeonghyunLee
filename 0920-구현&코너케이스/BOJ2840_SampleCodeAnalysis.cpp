#include <algorithm> //사용이 안 된 것 같다..?
#include <iostream> //입출력을 위한 헤더파일
#include <vector> //vector 사용을 위한 헤더파일
using namespace std; //cin, cout 등 할 때 앞에 std 안 쓰기 위해

typedef pair<int, char> ci; //pair<int, char>을 ci로 간추려 쓸 수 있다

/*
    - 배열을 ?로 초기화 해주고, 입력대로 처리한다
    - 문제의 경우, 화살표를 고정시키고 바퀴를 돌리는데,
    - 풀 때에는 바퀴를 고정시키고, 화살표를 이동시키는 방식으로 풀었다. (출력시 방향을 바꿔야함)
    <주의 사항>
    1. ?이 아닌 문자가 저장되어있는데, 다른 문자를 저장하려는 경우
    2. 룰렛에 중복되는 문자가 있는 경우
*/

string arrowStartWheel(int index, int n, vector<char>& wheel) { //특정 화살표에서 시작한 행운의 바퀴 리턴
    string ans = ""; //정답 저장할 문자열

    for (int i = n; i > 0; i--) { //i=n부터 i=1까지
        ans += wheel[(i + index) % n]; //리턴할 문자열에 wheel[(index+i)%n] 추가, n으로 나눈 나머지를 추가하는 이유는 한 바퀴 넘어갈 경우 대비
    }

    return ans; //정답 리턴
}

string makeWheel(int n, vector<ci>& record) { //바퀴가 어떻게 생겼는지 만드는 함수
    vector<char> wheel(n, '?');           //?로 초기화
    vector<bool> is_available(26, false); //알파벳 중복 체크

    int index = 0; //화살표가 가리키는 인덱스

    for (int i = 0; i < record.size(); i++) { //바퀴 회전 정보 수만큼 반복
        int rot = record[i].first; //화살표 회전 정도
        int ch = record[i].second;// 회전해서 가리킨 글자

        index = (index + rot) % n; //화살표 이동

        if (wheel[index] == ch) {// 이미 어떤 글자인지 아는 칸
            continue; //다음 정보로 이동
        }

        // 주의사항 체크
        if (wheel[index] != '?' || is_available[ch - 'A']) {// 다른 문자가 저장되어있거나, 이미 다른 곳에 문자가 사용된 경우
            return "!"; //상덕이가 적은 종이에 해당하는 행운의 바퀴 없음
        }

        wheel[index] = ch; //바퀴의 해당 index에 해당 글자 추가
        is_available[ch - 'A'] = true; // 2번 조건을 체크하기 위함
    }

    return arrowStartWheel(index, n, wheel); //마지막 회전에서 화살표가 가리키는 문자부터 시계방향으로 바퀴에 적어놓은 알파벳을 출력
}

int main() { //메인함수
    //입력
    int n, k; //n: 바퀴의 칸 수, k: 상덕이가 바퀴를 돌리는 횟수
    cin >> n >> k; //n, k 입력받기

    vector<ci> record(k, { 0, 0 }); //바퀴 회전 기록할 vector
    for (int i = 0; i < k; i++) { //k번 반복
        cin >> record[i].first >> record[i].second; //화살표가 회전한 칸 수, 회전을 멈추었을 때 가리키던 글자 입력 받기
    }

    //출력
    cout << makeWheel(n, record); //정답 출력
}