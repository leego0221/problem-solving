#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
int ans = -100'000'000; // 음수값 고려
int grid[11][11];
pair<int, int> arr[4];

bool is_adjacent(int cnt, int row, int col) {
	int dr[4] = { -1, 1, 0, 0 };
	int dc[4] = { 0, 0, -1, 1 };

	for (int i = 0; i < cnt; i++) {
		int r = arr[i].first;
		int c = arr[i].second;
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m) {
				continue;
			}
			if (row == nr && col == nc) {
				return true;
			}
		}
	}
	return false;
}

void backtracking(int cnt, int start) {
	if (cnt == k) {
		int sum = 0;
		for (int i = 0; i < k; i++) {
			sum += grid[arr[i].first][arr[i].second];
		}
		ans = max(ans, sum);
		return;
	}

	for (int i = start; i < n * m; i++) {
		// n은 고려 사항이 아님
		int row = i / m;
		int col = i % m;
		if (is_adjacent(cnt, row, col)) {
			continue;
		}
		arr[cnt] = make_pair(row, col);
		backtracking(cnt + 1, i + 1);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 입력
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	// 백트래킹
	backtracking(0, 0);

	// 출력
	cout << ans;
	return 0;
}