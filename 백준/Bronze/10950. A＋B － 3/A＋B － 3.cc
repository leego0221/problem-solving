#include <iostream>
using namespace std;

int main(void) {
	int count, a, b, sum;
	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> a;
		cin >> b;
		sum = a + b;
		cout << sum << endl;
	}
	return 0;
}