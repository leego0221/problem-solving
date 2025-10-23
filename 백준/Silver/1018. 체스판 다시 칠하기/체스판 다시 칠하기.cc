#include <iostream>
#define WHITE true
#define BLACK false
using namespace std;

bool board[51][51];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, row = 0, col = 0;
	int cnt, min = 64;
	bool curr, prev;
	char color;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> color;
			if (color == 'W') {
				board[i][j] = WHITE;
			}
			else if (color == 'B') {
				board[i][j] = BLACK;
			}
		}
	}

	while (row + 8 <= n) {
		prev = WHITE; // 첫번째 iter
		for (int iter = 0; iter < 2; iter++) {
			cnt = 0;
			for (int i = row; i < row + 8; i++) {
				for (int j = col; j < col + 8; j++) {
					curr = board[i][j];
					if (prev == curr) {
						cnt++;
						curr = !prev;
					}
					prev = curr;
				}
				prev = !prev; // 다음 줄 넘어갈 때 한 번 더 뒤집어줘야 함
			}
			if (cnt < min) {
				min = cnt;
			}
			prev = BLACK; // 두번째 iter
		}

		col++;
		if (col + 8 > m) {
			col = 0;
			row++;
		}
	}

	cout << min;
	return 0;
}