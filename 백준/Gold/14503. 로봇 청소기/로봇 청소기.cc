#include <iostream>
#include <queue>
using namespace std;

int room[51][51]; // 벽 유무 확인
int visited[51][51]; // 청소 유무 확인

int bfs(int row, int col, int curr_d) {
	int cnt = 0;
	int dr[4] = { -1, 0, 1, 0 };
	int dc[4] = { 0, 1, 0, -1 };
	queue<pair<int, int>> q;
	q.push(make_pair(row, col));
	visited[row][col] = 1;
	cnt++;

	while (!q.empty()) {
		bool found = false;
		int r, c, nr, nc;
		r = q.front().first;
		c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			curr_d = (curr_d == 0) ? 3 : curr_d - 1; // 반시계방향 회전
			nr = r + dr[curr_d];
			nc = c + dc[curr_d];
			if (room[nr][nc] == 0 && !visited[nr][nc]) {
				q.push(make_pair(nr, nc));
				visited[nr][nc] = visited[r][c] + 1;
				cnt++;
				found = true;
				break;
			}
		}
		
		int back_d = (curr_d + 2) % 4; // 후진 방향 설정
		int tmp_r = r + dr[back_d];
		int tmp_c = c + dc[back_d];
		while (!found) {
			if (room[tmp_r][tmp_c] == 1) {
				return cnt; // 작동 종료
			}

			for (int i = 0; i < 4; i++) {
				curr_d = (curr_d == 0) ? 3 : curr_d - 1; // 반시계방향 회전
				nr = tmp_r + dr[curr_d];
				nc = tmp_c + dc[curr_d];
				if (room[nr][nc] == 0 && !visited[nr][nc]) {
					q.push(make_pair(nr, nc));
					visited[nr][nc] = visited[r][c] + 1;
					cnt++;
					found = true;
					break;
				}
			}

			tmp_r += dr[back_d];
			tmp_c += dc[back_d];
		}
	}
	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, r, c, d;
	cin >> n >> m >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
		}
	}
	cout << bfs(r, c, d);
	return 0;
}