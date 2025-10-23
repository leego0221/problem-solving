#include <iostream>
using namespace std;

int a[100], b[100];

int main(void) {
	int x, n, sum = 0;
	cin >> x >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		sum += a[i] * b[i];
	}
	cout << (x == sum ? "Yes" : "No");
	return 0;
}