#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void) {
	queue<int> q;
	vector<int> v;
	int n, k, num;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}
	while (!q.empty()) {
		for (int i = 0; i < k; i++) {
			num = q.front();
			q.pop();
			if (i == k - 1) {
				v.push_back(num);
			} else {
				q.push(num);
			}
		}
	}

	cout << "<";
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter;
		if (iter == v.end() - 1) {
			cout << ">";
		} else {
			cout << ", ";
		}
	}
	return 0;
}