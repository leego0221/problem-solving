#include <iostream>
using namespace std;

int main(void) {
	int arr[5], res = 0;
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		res += arr[i] * arr[i];
	}
	cout << res % 10;
	return 0;
}