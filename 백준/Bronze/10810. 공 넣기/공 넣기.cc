#include <iostream>
using namespace std;

int basket[101];

int main(void) {
	int n, m, from, to, k;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> k;
		for (int j = from; j <= to; j++) {
			basket[j] = k;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << basket[i] << ' ';
	}
	return 0;
}