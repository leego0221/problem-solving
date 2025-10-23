#include <iostream>
using namespace std;

bool is_prime[1'000'001];

void sieve_of_eratosthenes() {
	for (int i = 2; i <= 1'000'000; i++) {
		is_prime[i] = true;
	}
	for (int i = 2; i * i <= 1'000'000; i++) {
		if (!is_prime[i]) {
			continue;
		}
		for (int j = i + i; j <= 1'000'000; j += i) {
			is_prime[j] = false;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;

	sieve_of_eratosthenes();
	while (1) {
		bool check = false;
		cin >> n;
		if (n == 0) {
			break;
		}

		for (int i = 3; i <= n; i++) {
			if (is_prime[i] && is_prime[n - i]) {
				check = true;
				cout << n << " = " << i << " + " << n - i << '\n';
				break;
			}
		}
		if (!check) {
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}
	return 0;
}