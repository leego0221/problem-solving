#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	int n, element;
	string cmd;
	stack<int> s;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd.compare("push") == 0) {
			cin >> element;
			s.push(element);
		}
		else if (cmd.compare("pop") == 0) {
			if (s.empty()) {
				cout << "-1\n";
			} else {
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (cmd.compare("size") == 0) {
			cout << s.size() << "\n";
		}
		else if (cmd.compare("empty") == 0) {
			cout << (s.empty() ? 1 : 0) << "\n";
		}
		else if (cmd.compare("top") == 0) {
			cout << (s.empty() ? -1 : s.top()) << "\n";
		}
	}
	return 0;
}