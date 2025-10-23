#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct person {
	int x; // weight
	int y; // height
};

int main(void) {
	int n;
	person p;
	vector<pair<person, int>> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p.x >> p.y;
		v.push_back(make_pair(p, 1));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			if (v[i].first.x < v[j].first.x && v[i].first.y < v[j].first.y) {
				v[i].second++;
			}
		}
	}

	for (auto iter = v.begin(); iter != v.end(); iter++) {
		cout << iter->second << ' ';
	}
	return 0;
}