#include <iostream>
#include <vector>
using namespace std;

int dice[4][3];
int map[21][21];
int cmd[1001];

// 1번 명령
void move_east() {
	dice[0][0] = dice[1][1];
	dice[1][1] = dice[1][0];
	dice[1][0] = dice[3][1];
	dice[3][1] = dice[1][2];
	dice[1][2] = dice[0][0];
}

// 2번 명령
void move_west() {
	dice[0][0] = dice[1][1];
	dice[1][1] = dice[1][2];
	dice[1][2] = dice[3][1];
	dice[3][1] = dice[1][0];
	dice[1][0] = dice[0][0];
}

// 3번 명령
void move_north() {
	dice[0][0] = dice[1][1];
	dice[1][1] = dice[2][1];
	dice[2][1] = dice[3][1];
	dice[3][1] = dice[0][1];
	dice[0][1] = dice[0][0];
}

// 4번 명령
void move_south() {
	dice[0][0] = dice[1][1];
	dice[1][1] = dice[0][1];
	dice[0][1] = dice[3][1];
	dice[3][1] = dice[2][1];
	dice[2][1] = dice[0][0];
}

// 주사위 바닥면 복사
void copy_bottom(int &space) {
	if (space == 0) {
		space = dice[3][1];
	}
	else {
		dice[3][1] = space;
		space = 0;
	}
}

// 주사위 윗면 출력
void print_top() {
	cout << dice[1][1] << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, x, y, k;
	pair<int, int> curr;

	// 입력
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> cmd[i];
	}

	// 주사위 이동
	curr = make_pair(x, y);
	for (int i = 0; i < k; i++) {

		// 명령 수행
		switch (cmd[i]) {
			case 1:
				if (curr.second == m - 1) {
					continue;
				}
				curr.second++;
				move_east();
				break;
			case 2:
				if (curr.second == 0) {
					continue;
				}
				curr.second--;
				move_west();
				break;
			case 3:
				if (curr.first == 0) {
					continue;
				}
				curr.first--;
				move_north();
				break;
			case 4:
				if (curr.first == n - 1) {
					continue;
				}
				curr.first++;
				move_south();
				break;
		}

		// 주사위 바닥면 복사
		copy_bottom(map[curr.first][curr.second]);

		// 주사위 윗면 출력
		print_top();
	}

	return 0;
}