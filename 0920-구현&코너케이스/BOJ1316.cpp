#include <iostream>
#include <vector>

using namespace std;

bool isGroupWord(string s) {
	vector<int> alphabet(26); // 알파벳 나오는 횟수 저장, 0으로 자동 초기화
	char last; //직전 알파벳 담을 변수

	for (int i = 0; i < s.length(); i++) {
		if (alphabet[s[i] - 'a'] > 0 && s[i] != last) //전에 이미 나온적 있는데 앞과 연속되지 않는 글자인 경우
			return false;
		alphabet[s[i] - 'a']++;
		last = s[i];
	}

	return true;
}

int main() {
	int n;
	cin >> n;

	int ans = 0;

	for (int i = 0; i < n; i++) {
		string word;
		cin >> word;

		if (isGroupWord(word))
			ans++;
	}

	cout << ans;

	return 0;
	
}