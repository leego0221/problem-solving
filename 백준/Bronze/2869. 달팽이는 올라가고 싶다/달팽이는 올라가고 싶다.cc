#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(void) {
	double a, b, v, days;
	cin >> a >> b >> v;
	days = (v - b) / (a - b);
	cout << fixed << setprecision(0) << ceil(days) << endl;
	return 0;
}