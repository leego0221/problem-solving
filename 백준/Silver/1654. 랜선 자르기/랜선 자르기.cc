#include <iostream>
#include <climits>
using namespace std;

int k, n;
int lan[10'001];

int find_length(long long low, long long high) {
	while (low < high) {
		long long mid = (low + high) / 2;
		int cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += lan[i] / mid;
		}

		if (cnt >= n) {
			low = mid + 1;
		}
		else {
			high = mid;
		}
	}
	return low - 1;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long max = 0;
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> lan[i];
		if (max < lan[i]) {
			max = lan[i];
		}
	}
	cout << find_length(0, max + 1);
	return 0;
}