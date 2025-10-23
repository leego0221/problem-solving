#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, cnt = 0;
	string name;
	set<string> never_heard;
	set<string> never_seen;
	vector<string> res;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> name;
		never_heard.insert(name);
	}
	for (int i = 0; i < m; i++) {
		cin >> name;
		never_seen.insert(name);
	}

	auto iter_n = never_heard.begin();
	auto iter_m = never_seen.begin();
	while (iter_n != never_heard.end() && iter_m != never_seen.end()) {
		if (*iter_n == *iter_m) {
			res.push_back(*iter_n);
			iter_n++, iter_m++;
			cnt++;
		}
		else if (*iter_n < *iter_m) {
			iter_n++;
		}
		else {
			iter_m++;
		}
	}

	cout << cnt << "\n";
	for (auto iter = res.begin(); iter != res.end(); iter++) {
		cout << *iter << "\n";
	}
	return 0;
}