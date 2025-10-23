#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int n, element;
	string cmd;
	queue<int> q;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd.compare("push") == 0) {
			cin >> element;
			q.push(element);
		}
		else if (cmd.compare("pop") == 0) {
			if (q.empty()) {
				cout << "-1\n";
			} else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (cmd.compare("size") == 0) {
			cout << q.size() << "\n";
		}
		else if (cmd.compare("empty") == 0) {
			cout << (q.empty() ? 1 : 0) << "\n";
		}
		else if (cmd.compare("front") == 0) {
			cout << (q.empty() ? -1 : q.front()) << "\n";
		}
		else if (cmd.compare("back") == 0) {
			cout << (q.empty() ? -1 : q.back()) << "\n";
		}
	}
	return 0;
}