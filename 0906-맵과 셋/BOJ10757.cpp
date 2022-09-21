#include <iostream>
#include <vector>

using namespace std;

vector<int> result(10001);

int add(const string& a, const string& b) {
	vector<int> A(10000);
	vector<int> B(10000);

	//-'0' 안하면 숫자(char형)의 아스키 코드 값이 나옴
	for (int i = 0; i < a.length(); i++) {
		A[i] = a[a.length() - i - 1] - '0'; //작은 자리 수부터 앞에 오게 저장
	}
	for (int i = 0; i < b.length(); i++) {
		B[i] = b[b.length() - i - 1] - '0'; //작은 자리 수부터 앞에 오게 저장
	}

	int temp = 0; //더할 때 사용
	int k = 0; //자릿수

	for (int i = 0; i < 10001; i++) {
		if (i >= a.length() && i >= b.length()) {
			if (temp == 1) {
				result[i] = 1;
				k = i;
			}
			else
				k = i - 1;
			break;
		}

		result[i] = (A[i] + B[i] + temp) % 10;
		temp = (A[i] + B[i] + temp) / 10;
	}

	return k;
}

int main() {

	string a, b;
	cin >> a >> b;

	int k = add(a, b);

	for (int i = k; i >= 0; i--) {
		cout << result[i];
	}

	return 0;
}