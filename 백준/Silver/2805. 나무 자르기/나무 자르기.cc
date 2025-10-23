#include <iostream>
#include <climits>
using namespace std;

int n, m;
int trees[1'000'001];

long long find_cutter_height(long long low, long long high) {
	long long mid, tree, sum;
	long long nearest_mid = 0, nearest_sum = LLONG_MAX; // 나무를 항상 딱 맞게 가져갈 수는 없음

	while (low <= high) {
		mid = (low + high) / 2;
		sum = 0;
		for (int i = 0; i < n; i++) {
			tree = trees[i] > mid ? trees[i] - mid : 0;
			sum += tree;
		}

		if (sum < m) {
			high = mid - 1;
		}
		else if (sum > m) {
			low = mid + 1;
			if (nearest_sum > sum) {
				nearest_sum = sum;
				nearest_mid = mid;
			}
		}
		else if (sum == m) {
			return mid;
		}
	}
	return nearest_mid;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tallest = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> trees[i];
		if (tallest < trees[i]) {
			tallest = trees[i];
		}
	}
	cout << find_cutter_height(0, tallest);
	return 0;
}