#include <iostream>
using namespace std;

int n, m, sum, res, diff = 999999;

int main(void) {
	cin >> n >> m;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (i != j && j != k && k != i) {
					sum = arr[i] + arr[j] + arr[k];
					if (diff > m - sum && 0 <= m - sum) {
						diff = m - sum;
						res = sum;
					}
				}
			}
		}
	}
	cout << res;

	delete[] arr;
	return 0;
}