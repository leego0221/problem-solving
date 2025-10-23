#include <iostream>
using namespace std;

int main(void) {
	int hour, minute;
	cin >> hour;
	cin >> minute;
	minute -= 45;
	if (minute < 0) {
		minute += 60;
		hour--;
	}
	if (hour < 0)
		hour += 24;
	cout << hour << ' ' << minute << endl;
	return 0;
}