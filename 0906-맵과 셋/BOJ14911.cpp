#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <string>

using namespace std;

map<int, int> m;

void pairing(vector<int> &v, int k) {
	for (int i = 0; i < v.size()-1; i++) {
		for (int j = i+1; j < v.size(); j++) {
			if (v[i] + v[j] == k)
				m[v[i]] = v[j];
		}
	}
}

int main() {
	string s;
	getline(cin, s);
	stringstream ss(s);

	int n, k;
	vector<int> v;

	while (ss >> n) {
		v.push_back(n);
	}
	cin >> k;

	pairing(v, k);
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << ' ' << iter->second << '\n';
	}
	cout << m.size();

	return 0;
}