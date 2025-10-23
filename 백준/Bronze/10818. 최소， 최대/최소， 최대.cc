#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	// 최솟값
	int min = 1000000;
	for (int i = 0; i < n; i++)
		if (min > arr[i])
			min = arr[i];
	// 최댓값
	int max = -1000000;
	for (int i = 0; i < n; i++)
		if (max < arr[i])
			max = arr[i];

	cout << min << ' ' << max << endl;
	delete[] arr;
	return 0;
}