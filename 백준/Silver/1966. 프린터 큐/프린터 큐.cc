#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, n, m, pri;

	cin >> t;
	while (t--) {
		queue<pair<int, bool>> q;
		int pri_cnt[10] = { 0, };
		int res = 0;

		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> pri;
			q.push(make_pair(pri, i == m ? true : false));
			pri_cnt[pri]++;
		}

		while (!q.empty()) {
			pair<int, bool> check = q.front();
			bool rearranged = false;

			for (int i = 1; i <= 9; i++) {
				if (i > check.first && pri_cnt[i] > 0) {
					q.pop();
					q.push(check);
					rearranged = true;
					break;
				}
			}

			if (!rearranged) {
				q.pop();
				pri_cnt[check.first]--;
				res++;
				if (check.second == true) {
					break;
				}
			}
		}
		cout << res << '\n';
	}
	return 0;
}