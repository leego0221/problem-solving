#include <iostream>
using namespace std;

int factorial(int n) {
	int res = 1;
	for (int i = n; i > 0; i--) {
		res *= i;
	}
	return res;
}

int main(void) {
	int n, k, res;
	cin >> n >> k;
	res = factorial(n) / (factorial(k) * factorial(n - k));
	cout << res;
	return 0;
}