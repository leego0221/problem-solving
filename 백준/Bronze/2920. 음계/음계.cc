#include <iostream>
using namespace std;

int arr[8];

int main(void) {
	bool is_ascending = false;
	bool is_descending = false;
	bool is_mixed = false;
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}

	if (arr[0] == 1) { // ascending
		for (int i = 0; i < 8; i++) {
			if (arr[i] == i + 1) {
				continue;
			} else {
				is_mixed = true;
				break;
			}
		}
		if (!is_mixed) is_ascending = true;
	}
	else if (arr[0] == 8) { // descending
		for (int i = 0; i < 8; i++) {
			if (arr[i] == 8 - i) {
				continue;
			} else {
				is_mixed = true;
				break;
			}
		}
		if (!is_mixed) is_descending = true;
	}
	else { // mixed
		is_mixed = true;
	}

	if (is_ascending) cout << "ascending";
	else if (is_descending) cout << "descending";
	else if (is_mixed) cout << "mixed";
	return 0;
}