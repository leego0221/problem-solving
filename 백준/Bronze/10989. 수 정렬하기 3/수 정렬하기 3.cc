#include <iostream>
using namespace std;

int arr[10001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[num]++;
	}

	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << i << "\n";
		}
	}
	return 0;
}