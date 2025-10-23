#include <iostream>
using namespace std;

int ans[200'002];
int s[10];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, a, b, cnt, max = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ans[i];
	}
	
	s[ans[0]]++;
	a = 0, b = 0;
	while (a < n && b < n) {
		cnt = 0;
		for (int i = 1; i <= 9; i++) {
			if (s[i] != 0) {
				cnt++;
			}
		}

		if (cnt <= 2) {
			if (max < b - a + 1) {
				max = b - a + 1;
			}
			b++;
			s[ans[b]]++;
		}
		else if (cnt >= 3) {
			s[ans[a]]--;
			a++;
		}
	}

	cout << max;
	return 0;
}