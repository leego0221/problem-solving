#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int tomato[101][101][101];
int days[101][101][101];
int m, n, h;

int bfs(vector<tuple<int, int, int>> &v) {
	int res = 1;
	int dx[6] = { -1, 1, 0, 0, 0, 0 };
	int dy[6] = { 0, 0, -1, 1, 0, 0 };
	int dz[6] = { 0, 0, 0, 0, -1, 1 };
	queue<tuple<int, int, int>> q;

	for (auto iter = v.begin(); iter != v.end(); iter++) {
		q.push(*iter);
	}

	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int z = get<2>(q.front());
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (nx < 0 || ny < 0 || nz < 0 ||
				nx >= h || ny >= n || nz >= m) {
				continue;
			}
			if (tomato[nx][ny][nz] == 0) {
				q.push(make_tuple(nx, ny, nz));
				res = tomato[nx][ny][nz] = tomato[x][y][z] + 1;
			}
		}
	}
	return res - 1;
}

int main(void) {
	int total_days = 0;
	vector<tuple<int, int, int>> ripe_tomatoes;
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1) {
					ripe_tomatoes.push_back(make_tuple(i, j, k));
				}
			}
		}
	}

	total_days = bfs(ripe_tomatoes);

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (tomato[i][j][k] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}
	cout << total_days;
	return 0;
}