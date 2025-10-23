#include <iostream>
using namespace std;

int n, m;
int ans[9];
bool visited[9];

void backtracking(int cnt, int start) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i <= n; i++) {
		ans[cnt] = i;
		backtracking(cnt + 1, i);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	backtracking(0, 1);
	return 0;
}