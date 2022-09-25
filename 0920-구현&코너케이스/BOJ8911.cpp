#include <iostream>
#include <vector>

using namespace std;

int turtle(string s) {
	int x = 0;
	int y = 0;
	int maxX = 0, minX = 0, maxY = 0, minY = 0;
	int direction = 0; //0: 북, 1: 서, 2: 남, 3: 동

	for (int i = 0; i < s.length(); i++) {
		switch (s[i])
		{
		case 'F':
			if (direction == 0)
				y++;
			else if (direction == 1)
				x--;
			else if (direction == 2)
				y--;
			else if (direction == 3)
				x++;

			if (x > maxX)
				maxX = x;
			if (x < minX)
				minX = x;
			if (y > maxY)
				maxY = y;
			if (y < minY)
				minY = y;

			break;

		case 'B':
			if (direction == 0)
				y--;
			else if (direction == 1)
				x++;
			else if (direction == 2)
				y++;
			else if (direction == 3)
				x--;

			if (x > maxX)
				maxX = x;
			if (x < minX)
				minX = x;
			if (y > maxY)
				maxY = y;
			if (y < minY)
				minY = y;

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

	return (maxX - minX) * (maxY - minY);
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