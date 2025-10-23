#include <iostream>
#include <algorithm>
using namespace std;

int basket[101];

int main(void) {
	int n, m, from, to;
	for (int i = 1; i <= 100; i++) {
		basket[i] = i;
	}

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		reverse(basket + from, basket + to + 1);
	}

	for (int i = 1; i <= n; i++) {
		cout << basket[i] << ' ';
	}
	return 0;
}