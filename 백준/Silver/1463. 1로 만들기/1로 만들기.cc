#include <iostream>
#include <algorithm>
using namespace std;

int dp[1'000'001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int x;
	cin >> x;

	for (int i = 2; i <= x; i++) {
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}

	cout << dp[x];
	return 0;
}