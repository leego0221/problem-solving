#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, m, n, x, y;
	cin >> t;

	while (t--) {
		int idx, num, first, ans = -1;
		cin >> m >> n >> x >> y;

		// 초기값 설정
		idx = x;
		num = x % n;
		if (num == 0) {
			num = n;
		}
		first = num;

		// 해 찾기
		if (num == y) {
			ans = idx;
		}
		else {
			do {
				num = (num + m) % n;
				if (num == 0) {
					num = n;
				}
				idx += m;

				if (num == y) {
					ans = idx;
				}
			} while (first != num);
		}
		cout << ans << '\n';
	}
	return 0;
}