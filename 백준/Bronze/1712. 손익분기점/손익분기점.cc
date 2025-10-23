#include <iostream>
using namespace std;

int main(void) {
	int a, b, c, breakEvenPoint;
	cin >> a >> b >> c;
	if (b >= c)
		breakEvenPoint = -1;
	else
		breakEvenPoint = a / (c - b) + 1;
	cout << breakEvenPoint << endl;
	return 0;
}