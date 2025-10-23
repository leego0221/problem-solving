#include <iostream>
using namespace std;

int main(void) {
	int arr[9];
	for (int i = 0; i < 9; i++)
		cin >> arr[i];

	int max = 0;
	for (int i = 0; i < 9; i++)
		if (max < arr[i])
			max = arr[i];

	int index;
	for (int i = 0; i < 9; i++)
		if (max == arr[i])
			index = i;

	cout << max << endl << index + 1 << endl;
	return 0;
}