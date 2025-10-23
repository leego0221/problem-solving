#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	string str1, str2;
	cin >> str1 >> str2;
	str1.insert(0, " ");
	str2.insert(0, " ");
	n = str1.size() - 1;
	m = str2.size() - 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (str1[i] == str2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	cout << dp[n][m];
	return 0;
}