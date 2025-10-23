#include <iostream>
using namespace std;

int n, cnt;
int ans[16];
bool visited[16];

bool check_area(int row) {
	for (int i = 0; i < row; i++) {
		if (ans[row] == ans[i] || row - i == abs(ans[row] - ans[i])) {
			return false;
		}
	}
	return true;
}

void backtracking(int row) {
	if (row == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			ans[row] = i;
			if (!check_area(row)) {
				continue;
			}
			visited[i] = true;
			backtracking(row + 1);
			visited[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	backtracking(0);
	cout << cnt;
	return 0;
}