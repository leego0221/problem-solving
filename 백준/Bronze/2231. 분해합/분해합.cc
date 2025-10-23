#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, sum, res = 0;
	string s;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum = i;
		s = to_string(i);
		for (int j = 0; j < s.length(); j++) {
			sum += s[j] - '0';
		}

		if (sum == n) {
			res = i;
			break;
		}
	}
	cout << res;
	return 0;
}