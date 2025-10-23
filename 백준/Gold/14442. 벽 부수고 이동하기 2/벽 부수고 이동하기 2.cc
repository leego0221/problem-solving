#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m, k;
char board[1001][1001];
int visited[11][1001][1001];

int bfs(int row, int col) {
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, row, col));
	visited[0][row][col] = 1;

	// 1x1은 그대로 1 리턴
	if (n == 1 && m == 1) {
		return 1;
	}

	while (!q.empty()) {
		int broken = get<0>(q.front());
		int x = get<1>(q.front());
		int y = get<2>(q.front());
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
				continue;
			}

			// 갈 수 있는 길이고, 해당 칸을 방문하지 않았을 경우
			if (board[nx][ny] == '0' && !visited[broken][nx][ny]) {
				q.push(make_tuple(broken, nx, ny));
				visited[broken][nx][ny] = visited[broken][x][y] + 1;
			}
			// 벽이고, 현재 부순 횟수가 k 미만이고, 해당 칸을 방문하지 않았을 경우
			else if (board[nx][ny] == '1' && broken < k && !visited[broken + 1][nx][ny]) {
				q.push(make_tuple(broken + 1, nx, ny));
				visited[broken + 1][nx][ny] = visited[broken][x][y] + 1;
			}

			if (nx == n - 1 && ny == m - 1) {
				return visited[broken][nx][ny];
			}
		}
	}
	return -1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	cout << bfs(0, 0);
	return 0;
}