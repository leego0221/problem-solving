#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum += (n / i) * i;
	}
	cout << sum;
	return 0;
}