#include <iostream>
using namespace std;

int main(void) {
	int x, n = 1, count = 0, numerator, denominator;
	cin >> x;
	while (x > 0) {
		x -= n++;
		count++;
	}
	if (count % 2) {
		denominator = count + x;
		numerator = count + 1 - denominator;
	}
	else {
		numerator = count + x;
		denominator = count + 1 - numerator;
	}
	cout << numerator << '/' << denominator << endl;
	return 0;
}