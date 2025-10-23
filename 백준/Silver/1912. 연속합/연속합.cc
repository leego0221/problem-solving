#include <iostream>
#include <algorithm>
using namespace std;

int arr[100'001];
int dp[100'001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	// dp[] 계산
	dp[1] = arr[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}
	cout << *max_element(dp + 1, dp + n + 1);
	return 0;
}