#include <iostream>
#include <algorithm>
using namespace std;

int stair[303], dp[303];

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> stair[i];
	}

	dp[1] = stair[1];
	dp[2] = stair[2] + dp[1];
	for (int i = 3; i <= n; i++) {
		dp[i] = stair[i] + max(dp[i - 2], dp[i - 3] + stair[i - 1]);
	}
	cout << dp[n];
	return 0;
}