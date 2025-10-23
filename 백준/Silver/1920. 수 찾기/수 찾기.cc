#include <iostream>
#include <algorithm>
using namespace std;

int N[100001], M[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> N[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> M[i];
	}
	sort(N, N + n);
	
	for (int i = 0; i < m; i++) {
		cout << binary_search(N, N + n, M[i]) << "\n";
	}
	return 0;
}