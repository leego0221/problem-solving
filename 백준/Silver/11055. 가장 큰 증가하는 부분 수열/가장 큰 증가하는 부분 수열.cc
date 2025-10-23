#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = arr[i];
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + arr[i]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (sum < dp[i]) {
			sum = dp[i];
		}
	}
	cout << sum;
	return 0;
}