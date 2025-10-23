#include <iostream>
using namespace std;

int main(void) {
	int arr[10], num = 10;
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
		arr[i] %= 42;
	}

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			if (arr[i] == -1)
				continue;
			if (arr[i] == arr[j] && i != j) {
				arr[j] = -1;
				num--;
			}
		}
	cout << num << endl;
	return 0;
}