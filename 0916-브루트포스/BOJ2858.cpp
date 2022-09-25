#include <iostream>

using namespace std;

// 2(L + W - 2) = R
// (L-2)*(W-2) = B
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int r, b;
	cin >> r >> b;

	for (int l = 3; ; l++) {
		for (int w = 3; w <= l; w++) {
			if (2 * (l + w - 2) == r && (l - 2) * (w - 2) == b) {
				cout << l << " " << w;
				return 0;
			}
		}
	}

}