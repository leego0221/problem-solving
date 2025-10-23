#include <iostream>
using namespace std;

bool visited[51][51];
int arr[51][51];
int m, n, worm;

void init() {
	worm = 0;
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			visited[i][j] = false;
			arr[i][j] = 0;
		}
	}
}

void dfs(int x, int y) {
	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { -1, 0, 1, 0 };
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx > m - 1 || ny > n - 1) {
			continue;
		}
		if (arr[nx][ny] == 1 && !visited[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int main(void) {
	int t, k, x, y;
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			arr[x][y] = 1;
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 1 && !visited[i][j]) {
					dfs(i, j);
					worm++;
				}
			}
		}
		cout << worm << '\n';
		init();
	}
	return 0;
}