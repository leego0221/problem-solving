#include <iostream>
#include <algorithm>
using namespace std;

int r, c, ans;
char board[21][21];
bool alphabet[26];

void dfs(int row, int col, int depth) {
	int dr[4] = { -1, 1, 0, 0 };
	int dc[4] = { 0, 0, -1, 1 };
	ans = max(ans, depth); // 최대 칸 수인지 체크

	for (int i = 0; i < 4; i++) {
		int nr = row + dr[i];
		int nc = col + dc[i];
		if (nr < 0 || nc < 0 || nr >= r || nc >= c) {
			continue;
		}
		if (!alphabet[board[nr][nc] - 'A']) {
			alphabet[board[nr][nc] - 'A'] = true;
			dfs(nr, nc, depth + 1);
			alphabet[board[nr][nc] - 'A'] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 입력
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
		}
	}
	
	// board[0][0] 알파벳 방문 처리
	alphabet[board[0][0] - 'A'] = true;

	// DFS 실행
	dfs(0, 0, 1);

	// 출력
	cout << ans;
	return 0;
}