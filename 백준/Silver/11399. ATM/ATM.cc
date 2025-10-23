#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n, num, sum = 0, res = 0;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end()); // 오름차순 정렬 시 합이 최소가 됨

	for (auto iter = v.begin(); iter != v.end(); iter++) {
		sum += *iter;
		res += sum;
	}
	cout << res;
	return 0;
}