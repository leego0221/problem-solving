#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int arr[500'005];
int cnt[8'008];

int main(void) {
	int n, mean, median, mode, range;
	int sum = 0, max_cnt = 0;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	// 산술평균
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		cnt[arr[i] + 4000]++; // 최빈값 위해 같이 계산
	}
	mean = round((double)sum / n);

	// 중앙값
	median = arr[n / 2];

	// 최빈값
	for (int i = 0; i < 8008; i++) {
		if (max_cnt < cnt[i]) {
			max_cnt = cnt[i];
			v.clear();
			v.push_back(i - 4000);
		}
		else if (max_cnt == cnt[i]) {
			v.push_back(i - 4000);
		}
	}
	sort(v.begin(), v.end());
	mode = v.size() >= 2 ? v[1] : v[0];

	// 범위
	range = arr[n - 1] - arr[0];

	cout << mean << '\n';
	cout << median << '\n';
	cout << mode << '\n';
	cout << range << '\n';
	return 0;
}