#include <iostream>
using namespace std;

int n, m;
int N[500'005];
int M[500'005];
int cnt[20'000'002];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> N[i];
		cnt[N[i] + 10'000'000]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> M[i];
	}

	for (int i = 0; i < m; i++) {
		cout << cnt[M[i] + 10'000'000] << " ";
	}
	return 0;
}