#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int m, x;
	int set = 0;
	string cmd;
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> cmd;
		if (cmd.compare("add") == 0) {
			cin >> x;
			set |= 1 << x;
		}
		else if (cmd.compare("remove") == 0) {
			cin >> x;
			set &= ~(1 << x);
		}
		else if (cmd.compare("check") == 0) {
			cin >> x;
			cout << (set & (1 << x) ? "1\n" : "0\n");
		}
		else if (cmd.compare("toggle") == 0) {
			cin >> x;
			set ^= 1 << x;
		}
		else if (cmd.compare("all") == 0) {
			set = -1;
		}
		else if (cmd.compare("empty") == 0) {
			set = 0;
		}
	}
	return 0;
}