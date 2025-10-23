#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[300'003];

int main(void) {
	int n, sum = 0;
	double trimmed, avg;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	trimmed = round(n * 0.15);
	for (int i = trimmed; i < n - trimmed; i++) {
		sum += arr[i];
	}
	avg = n != 0 ? round(sum / (n - trimmed * 2)) : 0;
	cout << avg;
	return 0;
}