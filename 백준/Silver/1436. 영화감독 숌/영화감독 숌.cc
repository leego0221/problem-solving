#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n, cnt = 0, num;
	string str;
	cin >> n;

	for (int i = 666; cnt < n; i++) {
		str = to_string(i);
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '6') {
				int temp = j, six_cnt = 1;

				while (++temp < str.size()) {
					if (str[temp] == '6') {
						six_cnt++;
					}
					else {
						break;
					}
				}
				if (six_cnt >= 3) {
					num = i;
					cnt++;
					break;
				}
			}
		}
	}
	cout << num;
	return 0;
}