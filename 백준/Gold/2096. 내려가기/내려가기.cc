#include <iostream>
#include <algorithm>
using namespace std;

int arr[100'000][3];
int tmp[3], dp[3];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	// 최대 점수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			dp[0] = max(tmp[0], tmp[1]) + arr[i][0];
			dp[1] = max(max(tmp[0], tmp[1]), tmp[2]) + arr[i][1];
			dp[2] = max(tmp[1], tmp[2]) + arr[i][2];
		}
		tmp[0] = dp[0];
		tmp[1] = dp[1];
		tmp[2] = dp[2];
	}
	cout << max(max(dp[0], dp[1]), dp[2]) << ' ';
	
	// 초기화
	tmp[0] = tmp[1] = tmp[2] = 0;

	// 최소 점수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			dp[0] = min(tmp[0], tmp[1]) + arr[i][0];
			dp[1] = min(min(tmp[0], tmp[1]), tmp[2]) + arr[i][1];
			dp[2] = min(tmp[1], tmp[2]) + arr[i][2];
		}
		tmp[0] = dp[0];
		tmp[1] = dp[1];
		tmp[2] = dp[2];
	}
	cout << min(min(dp[0], dp[1]), dp[2]);

	return 0;
}