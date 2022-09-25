#include <iostream>
#include <vector>
#include <stack>

using namespace std;

string password(string s) {
	stack<char> left; //커서(cursor) 왼쪽
	stack<char> right; //커서 오른쪽

	for (int i = 0; i < s.length(); i++) {
		switch (s[i])
		{
		case '<':
			if (left.empty())
				break;
			right.push(left.top());
			left.pop();
			break;
		case '>':
			if (right.empty())
				break;
			left.push(right.top());
			right.pop();
			break;
		case '-':
			if (left.empty())
				break;
			left.pop();
			break;
		default:
			left.push(s[i]);
			break;
		}
	}

	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}

	string ans = "";

	while (!right.empty()) {
		ans += right.top();
		right.pop();
	}

	return ans;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		cout << password(s) << '\n';
	}

	return 0;
}