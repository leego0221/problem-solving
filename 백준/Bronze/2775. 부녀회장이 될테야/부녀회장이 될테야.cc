#include <iostream>
using namespace std;
void InitArray(int* arr);

int main(void) {
	int floor[14];
	int t, k, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		InitArray(floor);
		cin >> k >> n;
		for (int j = 0; j < k; j++) {
			for (int l = 1; l < 14; l++) {
				floor[l] = floor[l - 1] + floor[l];
			}
		}
		cout << floor[n - 1] << endl;
	}
	return 0;
}

void InitArray(int* arr) {
	for (int i = 0; i < 14; i++)
		arr[i] = i + 1;
	return;
}