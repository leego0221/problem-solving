#include <iostream>
#include <algorithm>
#define R 0
#define G 1
#define B 2
using namespace std;

int house[1001][3];
int dp[1001][3];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> house[i][R] >> house[i][G] >> house[i][B];
	}

	for (int i = 1; i <= n; i++) {
		dp[i][R] = min(dp[i - 1][G], dp[i - 1][B]) + house[i][R];
		dp[i][G] = min(dp[i - 1][B], dp[i - 1][R]) + house[i][G];
		dp[i][B] = min(dp[i - 1][R], dp[i - 1][G]) + house[i][B];
	}
	cout << min(min(dp[n][R], dp[n][G]), dp[n][B]);
	return 0;
}