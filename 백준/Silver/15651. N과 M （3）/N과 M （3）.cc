#include <iostream>
using namespace std;

int n, m;
int ans[8];

void backtracking(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		ans[cnt] = i;
		backtracking(cnt + 1);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	backtracking(0);
	return 0;
}