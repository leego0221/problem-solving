#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, cheese, hour;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int graph[101][101];
bool visited[101][101];
vector<pair<int, int>> v;

void init_visited() {
	for (int i = 0; i < n; i++) {
		fill(visited[i], visited[i] + m, false);
	}
}

void check_boundary(int row, int col) {
	queue<pair<int, int>> q;
	q.push(make_pair(row, col));
	visited[row][col] = true;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
				continue;
			}
			if (!visited[nr][nc] && graph[nr][nc] == 0) {
				q.push(make_pair(nr, nc));
				visited[nr][nc] = true;
			}
		}
	}
}

bool about_to_melt(int r, int c) {
	int surface = 0; // 네 변

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
			continue;
		}
		if (visited[nr][nc]) {
			surface++;
		}
	}
	return surface >= 2;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1) {
				cheese++;
			}
		}
	}

	// 치즈가 모두 녹을 때까지 수행
	while (cheese != 0) {
		int contacted = 0;
		init_visited();
		check_boundary(0, 0);
		v.clear();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && about_to_melt(i, j)) {
					v.push_back(make_pair(i, j));
					contacted++;
				}
			}
		}

		for (auto iter = v.begin(); iter != v.end(); iter++) {
			graph[iter->first][iter->second] = 0;
		}
		cheese -= contacted;
		hour++;
	}
	
	// 출력
	cout << hour;
	return 0;
}