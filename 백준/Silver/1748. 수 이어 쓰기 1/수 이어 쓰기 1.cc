#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	int i, digit, res = 0;
	for (i = 100'000'000, digit = 9; i != 1; i /= 10, digit--) {
		if (n / i == 0) {
			continue;
		}
		res += (n - i + 1) * digit;
		n = i - 1;
	}
	res += n; // 일의 자리 계산

	cout << res;
	return 0;
}