#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> josephus(int n, int k) {
    queue<int> q;
    vector<int> v;

    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    int j = 1;
    while (!q.empty()) {
        if (j % k != 0) { //제거 차례 아님
            //앞에 있던 수 큐 뒤로 보내기 (원 다음 칸으로 이동)
            q.push(q.front());
            q.pop();
        }
        else { //제거 차례
            int ans = q.front();
            q.pop(); //제거
            if (q.empty()) {
                v.push_back(ans);
                return v;
            }
            v.push_back(ans);
        }
        j++;
    }
    return v;
}

int main() {
	int n, k;
	cin >> n >> k;

    vector<int> v = josephus(n, k);

    cout << "<";
    for (auto iter = v.begin(); iter != v.end() - 1; iter++) {
        cout << *iter << ", ";
    }
    cout << v[v.size()-1] << ">";

    return 0;
}