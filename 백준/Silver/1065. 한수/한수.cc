#include <iostream>
using namespace std;
int calc(int n);

int main(void) {
	int n;
	cin >> n;
	cout << calc(n);
	return 0;
}

int calc(int n) {
	if (n < 100)
		return n;
	else {
		int result = 99;
		for (int i = 100; i <= n; i++) {
			int frontDiff = (i / 100) - (i / 10 % 10);
			int backDiff = (i / 10 % 10) - (i % 10);
			if (frontDiff == backDiff)
				result++;
		}
		return result;
	}
}