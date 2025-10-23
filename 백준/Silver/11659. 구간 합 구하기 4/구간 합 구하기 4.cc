#include <iostream>
using namespace std;

int arr[100'001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, begin, end;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		arr[i + 1] += arr[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> begin >> end;
		cout << arr[end] - arr[begin - 1] << '\n';
	}
	return 0;
}