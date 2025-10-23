#include <iostream>
using namespace std;

int value[11];

int main(void) {
	int n, k, check, cnt = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> value[i];
	}

	for (int i = n; i >= 1; i--) {
		check = k / value[i];
		if (check > 0) {
			cnt += check;
			k -= check * value[i];
		}
		if (k == 0) {
			break;
		}
	}
	cout << cnt;
	return 0;
}