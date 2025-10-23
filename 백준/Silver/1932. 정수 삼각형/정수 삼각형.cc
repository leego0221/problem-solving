#include <iostream>
#include <algorithm>
using namespace std;

int triangle[501][501];
int dp[501][501];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		if (ans < dp[n][i]) {
			ans = dp[n][i];
		}
	}
	cout << ans;
	return 0;
}