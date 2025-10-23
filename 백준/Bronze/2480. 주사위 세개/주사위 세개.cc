#include <iostream>
using namespace std;

int max(int m, int n) {
	return m > n ? m : n;
}

int main(void) {
	int a, b, c, prize = 0;
	cin >> a >> b >> c;
	if (a == b && b == c) {
		prize = 10000 + a * 1000;
	}
	else if (a == b && b != c) {
		prize = 1000 + a * 100;
	}
	else if (b == c && c != a) {
		prize = 1000 + b * 100;
	}
	else if (c == a && a != b) {
		prize = 1000 + c * 100;
	}
	else if (a != b && b != c) {
		prize = max(max(a, b), c) * 100;
	}
	cout << prize;
	return 0;
}