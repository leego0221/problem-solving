#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int tomato[1001][1001];
int days[1001][1001];
int m, n;

int bfs(vector<pair<int, int>> &v) {
	int res = 1;
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};
	queue<pair<int, int>> q;

	// 처음에만 queue에 출발점을 여러 개 넣어주면 됨
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		q.push(*iter);
	}

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
			if (tomato[nx][ny] == 0) {
				q.push(make_pair(nx, ny));
				res = tomato[nx][ny] = tomato[x][y] + 1;
			}
		}
	}
	return res - 1;
}

int main(void) {
	int total_days = 0;
	vector<pair<int, int>> ripe_tomatoes;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				ripe_tomatoes.push_back(make_pair(i, j));
			}
		}
	}

	total_days = bfs(ripe_tomatoes);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << total_days;
	return 0;
}