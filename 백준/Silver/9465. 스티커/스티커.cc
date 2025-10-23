#include <iostream>
#include <algorithm>
using namespace std;

int sticker[2][100'001];
int dp[2][100'001];

void init() {
	for (int i = 0; i < 100'001; i++) {
		sticker[0][i] = sticker[1][i] = 0;
		dp[0][i] = dp[1][i] = 0;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, n;
	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> sticker[i][j];
			}
		}

		dp[0][1] = sticker[0][1];
		dp[1][1] = sticker[1][1];
		for (int i = 2; i <= n; i++) {
			int beyond = max(dp[0][i - 2], dp[1][i - 2]);
			dp[0][i] = max(beyond, dp[1][i - 1]) + sticker[0][i];
			dp[1][i] = max(beyond, dp[0][i - 1]) + sticker[1][i];
		}
		
		cout << max(dp[0][n], dp[1][n]) << '\n';
		init();
	}
	return 0;
}