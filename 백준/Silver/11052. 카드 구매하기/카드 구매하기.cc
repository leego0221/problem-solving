#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = arr[i];
		for (int j = 1; j <= i / 2; j++) {
			dp[i] = max(dp[i], dp[i - j] + dp[j]);
		}
	}
	cout << dp[n];
	return 0;
}