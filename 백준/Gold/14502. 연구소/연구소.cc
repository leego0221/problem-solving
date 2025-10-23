#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int lab[8][8];
vector<pair<int, int>> blank;
pair<int, int> selected[3];
bool visited[8][8];
int ans;

void init_lab() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			lab[i][j] = -1;
		}
	}
}

void init_visited() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			visited[i][j] = false;
		}
	}
}

void bfs(int row, int col) {
	int dr[4] = { -1, 1, 0, 0 };
	int dc[4] = { 0, 0, -1, 1 };
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
			if (!visited[nr][nc] && lab[nr][nc] != 1) {
				q.push(make_pair(nr, nc));
				visited[nr][nc] = true;
			}
		}
	}
}

void backtracking(int depth, int start) {
	if (depth == 3) {
		int cnt = 0;
		init_visited();
		for (int i = 0; i < 3; i++) {
			lab[selected[i].first][selected[i].second] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (lab[i][j] == 2 && !visited[i][j]) {
					bfs(i, j);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && lab[i][j] == 0) {
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);

		for (int i = 0; i < 3; i++) {
			lab[selected[i].first][selected[i].second] = 0;
		}
		return;
	}
	
	for (int i = start; i < blank.size(); i++) {
		selected[depth] = blank[i];
		backtracking(depth + 1, i + 1);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	init_lab();
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 0) {
				blank.push_back(make_pair(i, j));
			}
		}
	}
	
	backtracking(0, 0);
	cout << ans;
	return 0;
}