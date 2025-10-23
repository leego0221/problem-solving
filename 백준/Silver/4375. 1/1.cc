#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int num, cnt;
	long long only_one;

	while (cin >> num) {
		only_one = cnt = 1;
		while (1) {
			if (only_one % num == 0) {
				cout << cnt << '\n';
				break;
			}
			else {
				cnt++;
				only_one = only_one * 10 + 1;
				only_one %= num; // 모듈러 연산 수행
			}
		}
	}
	return 0;
}