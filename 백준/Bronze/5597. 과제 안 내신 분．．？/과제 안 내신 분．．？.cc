#include <iostream>
using namespace std;

bool student[31];

int main(void) {
	int n;
	for (int i = 0; i < 28; i++) {
		cin >> n;
		student[n] = true;
	}

	for (int i = 1; i <= 30; i++) {
		if (!student[i]) {
			cout << i << '\n';
		}
	}
	return 0;
}