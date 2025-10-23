#include <iostream>
using namespace std;

bool is_prime[1'000'001];

void sieve_of_eratosthenes() {
	for (int i = 2; i < 1'000'001; i++) {
		is_prime[i] = true;
	}

	for (int i = 2; i < 1'000'001; i++) {
		if (!is_prime[i]) {
			continue;
		}
		int j = i + i;
		while (j < 1'000'001) {
			is_prime[j] = false;
			j += i;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, n;
	cin >> m >> n;

	sieve_of_eratosthenes();
	for (int i = m; i <= n; i++) {
		if (is_prime[i]) {
			cout << i << '\n';
		}
	}
	return 0;
}