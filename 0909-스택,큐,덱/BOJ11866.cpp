#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

    cout << "<";
	int j = 1;
	while (!q.empty()) {
        if (j % k != 0) { //제거 차례 아님
            //앞에 있던 수 큐 뒤로 보내기 (원 다음 칸으로 이동)
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        else { //제거 차례
            int ans = q.front();
            q.pop(); //제거
            if (q.empty()) {
                cout << ans << ">";
                return 0;
            }
            cout << ans << ", ";
        }
		j++;
	}
}