#include <iostream>
using namespace std;

int main(void) {
	int n, cnt = 0;
	bool is_prime;
	cin >> n;
	int* arr = new int[n];
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		is_prime = true;
		if (arr[i] <= 1) {
			is_prime = false;
		}
		if (arr[i] == 2) {
			is_prime = true;
		}
		for (int j = 2; j < arr[i]; j++) {
			if (arr[i] % j == 0) {
				is_prime = false;
				break;
			}
		}
		if (is_prime) {
			cnt++;
		}
	}
	cout << cnt;

	delete[] arr;
	return 0;
}