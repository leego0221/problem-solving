#include <iostream>
#include <iomanip>
using namespace std;

int main(void) {
	int t, h, w, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> h >> w >> n;
		int room[2] = { 0, 0 };
		room[0] = n % h;
		room[1] = n / h + 1;
		if (room[0] == 0) {
			room[0] = h;
			room[1] = n / h;
		}
		cout << room[0] << setfill('0') << setw(2) << room[1] << endl;
	}
	return 0;
}