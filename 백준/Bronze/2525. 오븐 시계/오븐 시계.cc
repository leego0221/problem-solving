#include <iostream>
using namespace std;

int main(void) {
	int a, b, c, hour = 0, minute = 0;
	cin >> a >> b >> c;
	hour = a;
	minute = b + c;
	if (minute / 60 > 0) {
		hour += minute / 60;
		minute %= 60;
	}
	if (hour >= 24) {
		hour -= 24;
	}
	cout << hour << ' ' << minute;
	return 0;
}