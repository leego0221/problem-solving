#include <iostream>
#include <queue>
using namespace std;

int n, m;
int visited[101][101];
char maze[101][101];

void bfs(int row, int col) {
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1 ,1 };
	queue<pair<int, int>> q;
	q.push(make_pair(row, col));
	visited[row][col] = 1;

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
			if (maze[nx][ny] == '1' && visited[nx][ny] == 0) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = visited[x][y] + 1;
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
		}
	}

	bfs(0, 0);
	cout << visited[n - 1][m - 1];
	return 0;
}