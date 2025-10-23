#include <iostream>
#include <map>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, n;
	cin >> t;

	while (t--) {
		int cases = 1;
		map<string, int> map;
		string dummy, clothes;

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> dummy >> clothes;
			map[clothes]++;
		}

		for (auto iter = map.begin(); iter != map.end(); iter++) {
			cases *= iter->second + 1;
		}
		cout << cases - 1 << '\n';
	}
	return 0;
}