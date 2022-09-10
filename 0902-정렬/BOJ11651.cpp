#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
변수가 2개일 때는 구조체 선언 대신 pair 사용이 간편함

struct point {
	int x, y;
};

*/

typedef pair<int, int> p;

bool cmp(const p & a, const p & b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else return a.first < b.first;
}

int main() {
	int n;
	cin >> n;

	vector<p> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i].first << " " << arr[i].second << "\n";
	}
}