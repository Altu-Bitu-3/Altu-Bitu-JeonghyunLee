#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string & a, const string & b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}
	int sumA = 0;
	int sumB = 0;
	for (int i = 0; i < a.length(); i++) {
		if ('0' <= a[i] && a[i] <= '9')
			sumA += a[i] - '0';
		if ('0' <= b[i] && b[i] <= '9')
			sumB += b[i] - '0';
	}
	if (sumA != sumB) {
		return sumA < sumB;
	}
	return a < b;
}

int main() {
	int N; //기타의 개수
	cin >> N;

	vector<string> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << "\n";
	}
}