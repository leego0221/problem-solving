#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int l, a, mod = 1'234'567'891;
	long long r = 1, sum = 0;
	string str;
	cin >> l >> str;
	for (int i = 0; i < l; i++) {
		a = str[i] - 'a' + 1;
		sum = (sum % mod + a * r % mod) % mod;
		r = r * 31 % mod;
	}
	cout << sum;
	return 0;
}