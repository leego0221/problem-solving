#include <iostream>
#include <queue>
using namespace std;

int visited[1001][1001];
int arr[1001][1001];
int dist_arr[1001][1001];

void bfs(int row, int col) {
	bool reachable = (arr[row][col] == 2);
	int dy[4] = { 1, -1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	queue<pair<int, int>> q;
	q.push(make_pair(row, col));
	visited[row][col] = reachable ? 2 : 1; // 둘 다 true
	dist_arr[row][col] = reachable ? 0 : -1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (arr[ny][nx] == 1 && !visited[ny][nx]) {
				q.push(make_pair(ny, nx));
				visited[ny][nx] = reachable ? 2 : 1; // 둘 다 true
				dist_arr[ny][nx] = reachable ? dist_arr[y][x] + 1 : -1;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, row = 0, col = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				row = i, col = j;
			}
		}
	}

	bfs(row, col);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && !visited[i][j]) {
				bfs(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dist_arr[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}