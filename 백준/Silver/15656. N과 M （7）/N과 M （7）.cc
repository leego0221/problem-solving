#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int sequence[8], ans[8];

void backtracking(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		ans[cnt] = sequence[i];
		backtracking(cnt + 1);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> sequence[i];
	}
	sort(sequence, sequence + n);
	backtracking(0);
	return 0;
}