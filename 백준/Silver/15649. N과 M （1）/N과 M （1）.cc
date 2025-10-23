#include <iostream>
using namespace std;

int m, n;
int ans[9];
bool visited[9];

void backtracking(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			ans[cnt] = i;
			visited[i] = true;
			backtracking(cnt + 1);
			visited[i] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	backtracking(0);
	return 0;
}