#include <iostream>
#include <algorithm>
#define HORI 0
#define DIAG 1
#define VERT 2
using namespace std;

int house[33][33];
long long dp[33][33][3];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;

	// 입력
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> house[i][j];
		}
	}
	
	// dp[][][] 채우기
	dp[1][2][HORI] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 3; j <= n; j++) {
			if (house[i][j] == 1) {
				continue;
			}
			dp[i][j][HORI] = dp[i][j - 1][HORI] + dp[i][j - 1][DIAG];
			dp[i][j][VERT] = dp[i - 1][j][DIAG] + dp[i - 1][j][VERT];

			if (house[i - 1][j] == 1 || house[i][j - 1] == 1) {
				continue;
			}
			dp[i][j][DIAG] = dp[i - 1][j - 1][HORI] + dp[i - 1][j - 1][DIAG] + dp[i - 1][j - 1][VERT];
		}
	}
	
	// 출력
	cout << dp[n][n][HORI] + dp[n][n][DIAG] + dp[n][n][VERT];
	return 0;
}