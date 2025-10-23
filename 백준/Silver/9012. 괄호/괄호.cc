#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	int t;
	bool is_vps;
	string str;
	cin >> t;
	for (int i = 0; i < t; i++) {
		is_vps = true;
		stack<char> s;
		cin >> str;
		for (auto iter = str.begin(); iter != str.end(); iter++) {
			if (*iter == '(') {
				s.push(*iter);
			}
			else if (*iter == ')') {
				if (s.empty()) {
					is_vps = false;
					break;
				}
				s.pop();
			}
		}
		if (!s.empty()) {
			is_vps = false;
		}

		if (is_vps) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	return 0;
}