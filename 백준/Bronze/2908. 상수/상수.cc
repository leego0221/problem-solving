#include <iostream>
using namespace std;

int main(void) {
	int num1, num2, ans;
	cin >> num1 >> num2;
	num1 = (num1 % 10) * 100 + (num1 / 10 % 10) * 10 + (num1 / 100);
	num2 = (num2 % 10) * 100 + (num2 / 10 % 10) * 10 + (num2 / 100);
	ans = (num1 > num2) ? num1 : num2;
	cout << ans << endl;
	return 0;
}