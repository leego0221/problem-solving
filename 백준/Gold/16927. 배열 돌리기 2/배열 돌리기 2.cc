#include <iostream>
using namespace std;

int a[301][301];

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, r;

	// 입력
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	
	// 배열 돌리기
	int row_min = 1, col_min = 1, row_max = n, col_max = m;
	while (row_min <= row_max && col_min <= col_max) {
		// r 최적화
		int mod = ((row_max - row_min) + (col_max - col_min)) * 2;
		int cnt = r % mod;

		for (int i = 0; i < cnt; i++) {
			for (int j = col_min; j < col_max; j++) {
				swap(a[row_min][j], a[row_min][j + 1]);
			}
			for (int j = row_min; j < row_max; j++) {
				swap(a[j][col_max], a[j + 1][col_max]);
			}
			for (int j = col_max; j > col_min; j--) {
				swap(a[row_max][j], a[row_max][j - 1]);
			}
			for (int j = row_max; j > row_min + 1; j--) {
				swap(a[j][col_min], a[j - 1][col_min]);
			}
		}
		row_min++; col_min++; row_max--; col_max--;
	}

	// 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}