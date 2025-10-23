#include <iostream>
using namespace std;

int main(void) {
	int chess[6] = { 1, 1, 2, 2, 2, 8 };
	int piece;
	for (int i = 0; i < 6; i++) {
		cin >> piece;
		chess[i] -= piece;
	}
	for (int i = 0; i < 6; i++) {
		cout << chess[i] << ' ';
	}
	return 0;
}