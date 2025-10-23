#include <iostream>
#include <algorithm>
using namespace std;

int n, m, sum, max_value;
int paper[501][501];

void check_I_shape() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m - 4; j++) {
			sum = paper[i][j] + paper[i][j + 1] +
				paper[i][j + 2] + paper[i][j + 3];
			max_value = max(max_value, sum);
		}
	}

	for (int i = 0; i <= n - 4; i++) {
		for (int j = 0; j < m; j++) {
			sum = paper[i][j] + paper[i + 1][j] +
				  paper[i + 2][j] + paper[i + 3][j];
			max_value = max(max_value, sum);
		}
	}
}

void check_O_shape() {
	for (int i = 0; i <= n - 2; i++) {
		for (int j = 0; j <= m - 2; j++) {
			sum = paper[i][j] + paper[i][j + 1] + 
				  paper[i + 1][j] + paper[i + 1][j + 1];
			max_value = max(max_value, sum);
		}
	}
}

void check_L_shape() {
	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 2; j++) {
			sum = paper[i][j] + paper[i + 1][j] +
				  paper[i + 2][j] + paper[i + 2][j + 1];
			max_value = max(max_value, sum);
			sum = paper[i][j] + paper[i][j + 1] +
				  paper[i + 1][j + 1] + paper[i + 2][j + 1];
			max_value = max(max_value, sum);
			sum = paper[i][j + 1] + paper[i + 1][j + 1] +
				  paper[i + 2][j] + paper[i + 2][j + 1];
			max_value = max(max_value, sum);
			sum = paper[i][j] + paper[i][j + 1] +
				  paper[i + 1][j] + paper[i + 2][j];
			max_value = max(max_value, sum);
		}
	}

	for (int i = 0; i <= n - 2; i++) {
		for (int j = 0; j <= m - 3; j++) {
			sum = paper[i][j] + paper[i][j + 1] +
				  paper[i][j + 2] + paper[i + 1][j];
			max_value = max(max_value, sum);
			sum = paper[i + 1][j] + paper[i + 1][j + 1] +
				  paper[i + 1][j + 2] + paper[i][j + 2];
			max_value = max(max_value, sum);
			sum = paper[i][j] + paper[i + 1][j] +
				  paper[i + 1][j + 1] + paper[i + 1][j + 2];
			max_value = max(max_value, sum);
			sum = paper[i][j] + paper[i][j + 1] +
				  paper[i][j + 2] + paper[i + 1][j + 2];
			max_value = max(max_value, sum);
		}
	}
}

void check_Z_shape() {
	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 2; j++) {
			sum = paper[i][j] + paper[i + 1][j] +
				  paper[i + 1][j + 1] + paper[i + 2][j + 1];
			max_value = max(max_value, sum);
			sum = paper[i][j + 1] + paper[i + 1][j] +
				  paper[i + 1][j + 1] + paper[i + 2][j];
			max_value = max(max_value, sum);
		}
	}

	for (int i = 0; i <= n - 2; i++) {
		for (int j = 0; j <= m - 3; j++) {
			sum = paper[i][j + 1] + paper[i][j + 2] +
				  paper[i + 1][j] + paper[i + 1][j + 1];
			max_value = max(max_value, sum);
			sum = paper[i][j] + paper[i][j + 1] +
				  paper[i + 1][j + 1] + paper[i + 1][j + 2];
			max_value = max(max_value, sum);
		}
	}
}

void check_T_shape() {
	for (int i = 0; i <= n - 2; i++) {
		for (int j = 0; j <= m - 3; j++) {
			sum = paper[i][j] + paper[i][j + 1] +
				  paper[i][j + 2] + paper[i + 1][j + 1];
			max_value = max(max_value, sum);
			sum = paper[i][j + 1] + paper[i + 1][j] +
				  paper[i + 1][j + 1] + paper[i + 1][j + 2];
			max_value = max(max_value, sum);
		}
	}

	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 2; j++) {
			sum = paper[i][j + 1] + paper[i + 1][j] +
				  paper[i + 1][j + 1] + paper[i + 2][j + 1];
			max_value = max(max_value, sum);
			sum = paper[i][j] + paper[i + 1][j] +
				  paper[i + 1][j + 1] + paper[i + 2][j];
			max_value = max(max_value, sum);
		}
	}
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> paper[i][j];
		}
	}

	check_I_shape();
	check_O_shape();
	check_L_shape();
	check_Z_shape();
	check_T_shape();
	cout << max_value;
	return 0;
}