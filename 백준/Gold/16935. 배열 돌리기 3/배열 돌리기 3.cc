#include <iostream>
#define ARR1 1
#define ARR2 0
using namespace std;

int n, m, r;
int a1[101][101], a2[101][101];
int op[1001];
int (*src_arr)[101], (*dest_arr)[101];
bool setting, is_rotated;

// 원소 교환
void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

// 1. 상하 반전
void operation1(int row, int col) {
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			dest_arr[row - i + 1][j] = src_arr[i][j];
		}
	}
}

// 2. 좌우 반전
void operation2(int row, int col) {
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			dest_arr[i][col - j + 1] = src_arr[i][j];
		}
	}
}

// 3. 오른쪽으로 90도 회전
void operation3(int row, int col) {
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			dest_arr[j][row - i + 1] = src_arr[i][j];
		}
	}
}

// 4. 왼쪽으로 90도 회전
void operation4(int row, int col) {
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			dest_arr[col - j + 1][i] = src_arr[i][j];
		}
	}
}

// 5. 오른쪽으로 그룹 단위 90도 회전
void operation5(int row, int col) {
	for (int i = 1; i <= row / 2; i++) {
		for (int j = 1; j <= col / 2; j++) {
			swap(src_arr[i][j], src_arr[i + row / 2][j]);
		}
	}
	for (int i = row / 2 + 1; i <= row; i++) {
		for (int j = 1; j <= col / 2; j++) {
			swap(src_arr[i][j], src_arr[i][j + col / 2]);
		}
	}
	for (int i = row / 2 + 1; i <= row; i++) {
		for (int j = col / 2 + 1; j <= col; j++) {
			swap(src_arr[i][j], src_arr[i - row / 2][j]);
		}
	}
}

// 6. 왼쪽으로 그룹 단위 90도 회전
void operation6(int row, int col) {
	for (int i = 1; i <= row / 2; i++) {
		for (int j = 1; j <= col / 2; j++) {
			swap(src_arr[i][j], src_arr[i][j + col / 2]);
		}
	}
	for (int i = 1; i <= row / 2; i++) {
		for (int j = col / 2 + 1; j <= col; j++) {
			swap(src_arr[i][j], src_arr[i + row / 2][j]);
		}
	}
	for (int i = row / 2 + 1; i <= row; i++) {
		for (int j = col / 2 + 1; j <= col; j++) {
			swap(src_arr[i][j], src_arr[i][j - col / 2]);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int row = n, col = m;

	// 입력
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a1[i][j];
		}
	}
	for (int i = 1; i <= r; i++) {
		cin >> op[i];
	}

	// 배열 돌리기
	setting = ARR1;
	for (int i = 1; i <= r; i++) {
		if (setting == ARR1) {
			src_arr = a1, dest_arr = a2;
		}
		else if (setting == ARR2) {
			src_arr = a2, dest_arr = a1;
		}
		if (is_rotated) {
			row = m; col = n;
		}
		else {
			row = n; col = m;
		}

		switch (op[i]) {
			case 1:
				operation1(row, col);
				break;
			case 2:
				operation2(row, col);
				break;
			case 3:
				operation3(row, col);
				break;
			case 4:
				operation4(row, col);
				break;
			case 5:
				operation5(row, col);
				break;
			case 6:
				operation6(row, col);
				break;
		}
		
		if (op[i] == 3 || op[i] == 4) {
			is_rotated = !is_rotated;
		}
		if (op[i] == 5 || op[i] == 6) {
			for (int i = 1; i <= row; i++) {
				for (int j = 1; j <= col; j++) {
					dest_arr[i][j] = src_arr[i][j];
				}
			}
		}
		setting = !setting;
	}

	// 출력
	if (is_rotated) {
		row = m; col = n;
	}
	else {
		row = n; col = m;
	}
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cout << dest_arr[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}