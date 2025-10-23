#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string str[5];
	int max_len = 0;
	for (int i = 0; i < 5; i++) {
		cin >> str[i];
		if (max_len < str[i].size()) {
			max_len = str[i].size();
		}
	}

	for (int idx = 0; idx < max_len; idx++) {
		for (int i = 0; i < 5; i++) {
			if (idx >= str[i].size()) {
				continue;
			}
			cout << str[i][idx];
		}
	}
	return 0;
}