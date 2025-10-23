#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
char board[1001][1001];
int visited[1001][1001][2]; // 벽을 부쉈는지 확인하기 위한 추가 인덱스가 필요

int bfs(int row, int col) {
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(row, col, 0));
	visited[row][col][0] = 1;

	if (n == 1 && m == 1) {
		return 1;
	}

	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int broken = get<2>(q.front());
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
				continue;
			}

			// 벽이 없고 아직 방문하지 않은 경우
			if (board[nx][ny] == '0' && !visited[nx][ny][broken]) {
				q.push(make_tuple(nx, ny, broken));
				visited[nx][ny][broken] = visited[x][y][broken] + 1;
			}
			// 벽이 있고 아직 벽을 뚫지 않은 경우
			else if (board[nx][ny] == '1' && broken == 0) {
				q.push(make_tuple(nx, ny, broken + 1));
				visited[nx][ny][broken + 1] = visited[x][y][broken] + 1;
			}

			if (nx == n - 1 && ny == m - 1) {
				return visited[nx][ny][broken]; // BFS는 가장 먼저 도달한 것을 반환
			}
		}
	}
	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	cout << bfs(0, 0) << '\n';
	return 0;
}