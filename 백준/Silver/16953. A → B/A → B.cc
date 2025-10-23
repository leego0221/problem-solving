#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b, cnt = 1;
	cin >> a >> b;

	while (b != a) {
		if (b % 10 == 1) {
			b /= 10;
		}
		else if (b % 2 == 0) {
			b /= 2;
		}
		else {
			cnt = -1;
			break;
		}

		if (b < a) {
			cnt = -1;
			break;
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}