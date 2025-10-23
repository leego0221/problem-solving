#include <iostream>
#define HORIZONTAL 0
#define DIAGONAL 1
#define VERTICAL 2
using namespace std;

int n, cnt;
int house[17][17];
int visited[17][17];
int state; // 0: 가로, 1: 대각선, 2: 세로

void dfs(int r, int c) {
	if (r == n && c == n) {
		cnt++;
		return;
	}

	int dr[3] = { 0, 1, 1 };
	int dc[3] = { 1, 1, 0 };
	int curr_state = state;
	visited[r][c] = true; // 방문 처리

	for (int i = 0; i < 3; i++) {
		if (curr_state == HORIZONTAL && i == VERTICAL ||
			curr_state == VERTICAL && i == HORIZONTAL) {
			continue;
		}
		
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 1 || nc < 1 || nr > n || nc > n) {
			continue;
		}
		if (!visited[nr][nc] && house[nr][nc] != 1) {
			if (i == DIAGONAL) {
				if (house[r + dr[0]][c + dc[0]] == 1 ||
					house[r + dr[2]][c + dc[2]] == 1) {
					continue;
				}
			}
			state = i; // state 갱신
			dfs(nr, nc); // 재귀 호출
			state = curr_state; // state 원상복귀
			visited[nr][nc] = false; // 다시 미방문 처리
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 입력
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> house[i][j];
		}
	}

	// (1, 2)에서 시작
	dfs(1, 2);

	// 출력
	cout << cnt;
	return 0;
}