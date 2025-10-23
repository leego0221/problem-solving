#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int n, num = 1;
	queue<int> q;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (1) {
		q.pop();
		if (q.empty()) {
			break;
		}
		num = q.front();
		q.pop();
		q.push(num);
	}
	cout << num;
	return 0;
}