#include <iostream>
using namespace std;

int dp[50001];
int square[50001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, idx = 0;
	cin >> n;

	// 제곱수 찾기
	square[idx++] = 0;
	for (int i = 1; i * i <= 50000; i++) {
		square[idx++] = i * i;
		dp[i * i] = 1;
	}

	idx = 1; // square[1] = 1;
	dp[2] = 2; dp[3] = 3;
	for (int i = 4; i <= n; i++) {
		int min = 50000;

		// 제곱수는 넘어감
		if (dp[i] == 1) {
			idx++;
			continue;
		}

		// 최소 개수 찾기
		for (int j = idx; j > 0; j--) {
			dp[i] = dp[square[j]] + dp[i - square[j]];
			if (min > dp[i]) {
				min = dp[i];
			}
		}
		dp[i] = min;
	}

	cout << dp[n];
	return 0;
}