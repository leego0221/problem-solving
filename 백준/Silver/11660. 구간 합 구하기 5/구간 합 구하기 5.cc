#include <iostream>
using namespace std;

int arr[1025][1025];
int dp[1025][1025];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, x1, y1, x2, y2, sum;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] += dp[i][j - 1] + arr[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		sum = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x <= x2; x++) {
			sum += dp[x][y2] - dp[x][y1 - 1];
		}
		cout << sum << '\n';
	}
	return 0;
}