//처음에는 set을 이용했지만 이 문제는 set을 이용한다면 비효율적(시간초과)
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr(21);

void solution(string str) {
	if (str == "all") {
		fill(arr.begin(), arr.end(), 1);
	}
	else if (str == "empty") {
		fill(arr.begin(), arr.end(), 0);
	}
	else {
		int num;
		cin >> num;

		if (str == "add") {
			arr[num] = 1;
		}
		else if (str == "remove") {
			arr[num] = 0;
		}
		else if (str == "check") {
			cout << arr[num] << "\n";
		}
		else if (str == "toggle") {
			if (arr[num] == 1) {
				arr[num] = 0;
			}
			else if (arr[num] == 0)
				arr[num] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M; //연산의 수

	cin >> M;

	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		solution(str);
	}

	return 0;
}