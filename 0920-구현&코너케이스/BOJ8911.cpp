#include <iostream>
#include <vector>

using namespace std;

int turtle(string s) {
	int x = 0;
	int y = 0;
	int max_x = 0, min_x = 0, max_y = 0, min_y = 0;

	//북 서 남 동
	int dx[4] = { 0, -1, 0, 1 };
	int dy[4] = { 1, 0, -1, 0 };

	int direction = 0; //0: 북, 1: 서, 2: 남, 3: 동

	for (int i = 0; i < s.length(); i++) {
		switch (s[i])
		{
		case 'F':
			x += dx[direction];
			y += dy[direction];

			if (x > max_x)
				max_x = x;
			if (x < min_x)
				min_x = x;
			if (y > max_y)
				max_y = y;
			if (y < min_y)
				min_y = y;

			break;

		case 'B':
			x -= dx[direction];
			y -= dy[direction];

			if (x > max_x)
				max_x = x;
			if (x < min_x)
				min_x = x;
			if (y > max_y)
				max_y = y;
			if (y < min_y)
				min_y = y;

			break;

		case 'L':
			direction++;
			direction %= 4;
			break;
		case 'R':
			direction--;
			direction += 4; //음수 나올 경우 위해
			direction %= 4;
			break;
		default:
			break;
		}
	}

	return (max_x - min_x) * (max_y - min_y);
}

int main() {
	int t; // 테스트 케이스 개수
	cin >> t;

	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		cout << turtle(s) << "\n";
	}

	return 0;
}