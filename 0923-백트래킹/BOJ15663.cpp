#include <iostream>
//#include <vector>
#include <algorithm>

using namespace std;
const int SIZE = 8;

int n, m;
int v[SIZE];
int ans[SIZE];
bool check[SIZE];
/*
vector<int> v(SIZE);
vector<int> ans(SIZE);
vector<bool> check(SIZE); //0(false)으로 초기화됨
*/

void backtracking(int cnt) {
	if (cnt == m) { //m개 수 고름
		for (int i = 0; i < cnt; i++) {
			cout << ans[i] << ' ';
		}
		cout << "\n";
		return;
	}

	int temp = -1; //중복 방지 위해
	for (int i = 0; i < n; i++) {
		if (!check[i] && temp != v[i]) {
			ans[cnt] = v[i];
			temp = ans[cnt];
			check[i] = true;
			backtracking(cnt + 1);
			check[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v, v + n);
	//sort(v.begin(), v.end()); 이유는 모르겠는데 sort를 하고 나면 vector 안의 값들이 다 0이 되어 있다.
	backtracking(0);
	return 0;
}