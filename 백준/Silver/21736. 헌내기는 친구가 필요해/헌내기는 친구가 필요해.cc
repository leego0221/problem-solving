#include <iostream>
#include <queue>
using namespace std;

int n, m;
char campus[601][601];

int bfs(int row, int col) {
	int person = 0;
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	queue<pair<int, int>> q;
	q.push(make_pair(row, col));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
				continue;
			}

			if (campus[nx][ny] == 'O') {
				q.push(make_pair(nx, ny));
				campus[nx][ny] = 'I';
			}
			else if (campus[nx][ny] == 'P') {
				q.push(make_pair(nx, ny));
				campus[nx][ny] = 'I';
				person++;
			}
		}
	}
	return person;
}

int main(void) {
	int person, doyeon_x = 0, doyeon_y = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> campus[i][j];
			if (campus[i][j] == 'I') {
				doyeon_x = i;
				doyeon_y = j;
			}
		}
	}

	person = bfs(doyeon_x, doyeon_y);
	if (person == 0) {
		cout << "TT";
	}
	else {
		cout << person;
	}
	return 0;
}