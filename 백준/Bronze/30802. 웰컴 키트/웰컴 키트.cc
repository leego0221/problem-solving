#include <iostream>
using namespace std;

int main(void) {
	int n, arr[6], t, p, shirts = 0;

	cin >> n;
	for (int i = 0; i < 6; i++) {
		cin >> arr[i]; // s, m, l, xl, xxl, xxxl
	}
	cin >> t >> p;

	for (int i = 0; i < 6; i++) {
		if (arr[i] == 0) {
			continue;
		}
		shirts += (arr[i] - 1) / t + 1;
	}

	cout << shirts << "\n"; // shirts
	cout << n / p << " " << n % p << "\n"; // pen

	return 0;
}