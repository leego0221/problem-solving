#include <iostream>
#include <queue>
using namespace std;

int l;
int dist[300][300];

void init_dist() {
	for (int i = 0; i < 300; i++) {
		for (int j = 0; j < 300; j++) {
			dist[i][j] = -1;
		}
	}
}

int bfs(int src_x, int src_y, int dest_x, int dest_y) {
	int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
	queue<pair<int, int>> q;
	q.push(make_pair(src_x, src_y));
	dist[src_x][src_y] = 0;

	if (src_x == dest_x && dest_x == dest_y) {
		return 0;
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= l || ny >= l) {
				continue;
			}
			if (dist[nx][ny] == -1) {
				q.push(make_pair(nx, ny));
				dist[nx][ny] = dist[x][y] + 1;
				if (nx == dest_x && ny == dest_y) {
					return dist[nx][ny];
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, src_x, src_y, dest_x, dest_y;
	cin >> t;
	while (t--) {
		init_dist();
		cin >> l >> src_x >> src_y >> dest_x >> dest_y;
		cout << bfs(src_x, src_y, dest_x, dest_y) << '\n';
	}
	return 0;
}