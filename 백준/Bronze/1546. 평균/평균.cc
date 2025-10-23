#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	double max = 0, sum = 0;
	double* arr = new double[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (max < arr[i])
			max = arr[i];
	}

	for (int i = 0; i < n; i++) {
		arr[i] = arr[i] / max * 100;
		sum += arr[i];
	}
	cout << sum / n << endl;
	delete[] arr;
	return 0;
}