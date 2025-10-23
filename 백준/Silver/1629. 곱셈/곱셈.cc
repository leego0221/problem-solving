#include <iostream>
using namespace std;

long long power(long long a, long long b, long long c) {
	if (b == 1) {
		return a % c;
	}
	else {
		long long x = power(a, b / 2, c);
		if (b % 2 == 0) { // 짝수
			return ((x % c) * (x % c)) % c;
		}
		else { // 홀수
			return (((x % c) * (x % c)) % c * (a % c)) % c;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long a, b, c;
	cin >> a >> b >> c;
	cout << power(a, b, c) % c;
	return 0;
}