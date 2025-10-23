#include <iostream>
#define BLUE 1
#define WHITE 0
using namespace std;

int paper[128][128];
int blue_cnt, white_cnt;

void cut_paper(int row, int col, int n) {
	int color = paper[row][col];
	bool same = true;

	for (int i = row; i < row + n; i++) {
		for (int j = col; j < col + n; j++) {
			if (color != paper[i][j]) {
				same = false;
				cut_paper(row, col, n / 2);
				cut_paper(row, col + n / 2, n / 2);
				cut_paper(row + n / 2, col, n / 2);
				cut_paper(row + n / 2, col + n / 2, n / 2);
				break;
			}
		}
		if (!same) {
			break;
		}
	}

	if (same) {
		if (color == BLUE) {
			blue_cnt++;
		}
		else if (color == WHITE) {
			white_cnt++;
		}
	}
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}
	cut_paper(0, 0, n);
	cout << white_cnt << '\n' << blue_cnt;
	return 0;
}