#include <iostream>
using namespace std;

int gcd(int a, int b) {
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main(void) {
	int a, b, gcd_num, lcm_num;
	cin >> a >> b;
	
	gcd_num = gcd(a, b);
	lcm_num = lcm(a, b);
	cout << gcd_num << "\n" << lcm_num << "\n";
	return 0;
}