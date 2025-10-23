#include <iostream>
using namespace std;

int main(void) {
	int n, fiveKg = 0, threeKg = 0;
	cin >> n;
	while (n > 0) {
		if (n == 1 || n == 2) {
			n -= 2; fiveKg = 0, threeKg = -1;
		}
		else if (n == 3 || n == 4) {
			n -= 3; threeKg++;
		}
		else if (n % 5 == 0) {
			n -= 5; fiveKg++;
		}
		else if (n == 6) {
			n -= 6; threeKg += 2;
		}
		else if (n == 9) {
			n -= 9; threeKg += 3;
		}
		else if (n == 12) {
			n -= 12; threeKg += 4;
		}
		else {
			n -= 5; fiveKg++;
		}
	}
	cout << fiveKg + threeKg;
	return 0;
}