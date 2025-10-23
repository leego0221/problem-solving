#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, num, max_num, min_num;
	vector<int> factors;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		factors.push_back(num);
	}

	max_num = *max_element(factors.begin(), factors.end());
	min_num = *min_element(factors.begin(), factors.end());
	cout << max_num * min_num;
	return 0;
}