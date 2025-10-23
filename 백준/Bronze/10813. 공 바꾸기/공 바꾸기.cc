#include <iostream>
using namespace std;

int arr[101];

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main(void) {
	int n, m, from, to;
	for (int i = 1; i <= 100; i++) {
		arr[i] = i;
	}

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		swap(arr[from], arr[to]);
	}
	
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}