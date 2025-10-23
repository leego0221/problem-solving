#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, num;
	vector<int> v;
	vector<int> v_s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
		v_s.push_back(num);
	}

	sort(v_s.begin(), v_s.end());
	v_s.erase(unique(v_s.begin(), v_s.end()), v_s.end());
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		cout << lower_bound(v_s.begin(), v_s.end(), *iter) - v_s.begin() << ' ';
	}
	return 0;
}