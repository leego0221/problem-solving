#include <iostream>
using namespace std;

long long dp[1'000'001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, n;
	cin >> t;

	for (int i = 1; i <= 1'000'000; i++) {
		for (int j = i; j <= 1'000'000; j += i) {
			dp[j] += i;
		}
	}
	for (int i = 1; i <= 1'000'000; i++) {
		dp[i] += dp[i - 1];
	}

	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}