#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, cnt;
char map[26][26];
bool visited[26][26];

void dfs(int x, int y) {
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	visited[x][y] = true;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
			continue;
		}
		if (map[nx][ny] == '1' && !visited[nx][ny]) {
			dfs(nx, ny);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int total = 0;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '1' && !visited[i][j]) {
				dfs(i, j);
				total++;
				v.push_back(cnt);
				cnt = 0;
			}
		}
	}
	sort(v.begin(), v.end());

	cout << total << '\n';
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << '\n';
	}
	return 0;
}