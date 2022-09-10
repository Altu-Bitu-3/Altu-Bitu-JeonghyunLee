#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long addTip(vector<int> tip, int N) {
	long tip_all = 0; //범위 때문에 int 형 쓰면 오버플로우 일어난다

	for (int i = 0; i < N; i++) {
		tip[i] = tip[i] - i; //i는 (등수 - 1)
		if (tip[i] > 0)
			tip_all += tip[i];
	}

	return tip_all;
}

int main() {
	int N; //사람의 수
	cin >> N;

	/*
	vector<int> original_tip(N); //각 사람이 주려고 하는 팁
	vector<int> final_tip(N); //강호가 받는 팁
	*/

	vector<int> tip(N); //변수 최소한으로 사용하는 것이 메모리 절약에 좋음

	for (int i = 0; i < N; i++) {
		cin >> tip[i];
	}


	//팁 많이 주려고 하는 사람부터 받기 -> 내림차순 정렬
	//처음에는 음수이면 팁 안 주므로 적게 팁 주는 사람이 앞에 오게끔 오름차순 정렬을 했는데,
	//그렇게 하면 많이 주는 사람이 팁을 못 줄 수가 있어서 최댓값이 아님
	sort(tip.begin(), tip.end(), greater<>());

	long tip_all = addTip(tip, N);

	cout << tip_all;
}