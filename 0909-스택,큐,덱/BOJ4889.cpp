#include <iostream>
#include <stack>

using namespace std;

int makeStable(string& s) {
	stack<char> st;
	int n = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '{') {
			st.push('{');
		}
		else if (s[i] == '}') {
			if (st.empty()) {
				n++;
				st.push('{');
			}
			else
				st.pop();
		}
	}

	return n + st.size()/2;
}

int main() {

	int i = 1;

	while (true) {
		string testcase;
		cin >> testcase;

		if (testcase.find("-") != string::npos) {
			break;
		}

		int ans = makeStable(testcase);
		
		cout << i << ". " << ans << "\n";

		i++;

	}

	return 0;
}