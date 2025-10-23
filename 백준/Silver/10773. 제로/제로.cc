#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int n, num, sum = 0;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		num == 0 ? v.pop_back() : v.push_back(num);
	}
	
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		sum += *iter;
	}
	cout << sum;
	return 0;
}