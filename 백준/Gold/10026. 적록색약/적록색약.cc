#include <iostream>
#include <queue>
using namespace std;

int n;
bool visited[101][101];
char grid[101][101];

void init_visited() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
}

void bfs(int row, int col, bool has_color_weakness) {
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	char color[2];
	queue <pair<int, int>> q;
	q.push(make_pair(row, col));
	visited[row][col] = true;

	color[0] = grid[row][col];
	if (has_color_weakness) {
		if (color[0] == 'R') {
			color[1] = 'G';
		}
		else if (color[0] == 'G') {
			color[1] = 'R';
		}
	}
	else {
		color[1] = color[0];
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
				continue;
			}
			if ((grid[nx][ny] == color[0] || grid[nx][ny] == color[1])
				&& !visited[nx][ny]) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
}

int main(void) {
	int ordinary_person = 0, color_weakness = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				bfs(i, j, false);
				ordinary_person++;
			}
		}
	}
	init_visited();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				bfs(i, j, true);
				color_weakness++;
			}
		}
	}

	cout << ordinary_person << ' ' << color_weakness;
	return 0;
}