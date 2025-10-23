#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int arr[10001];
int dist[10001];
pair<int, char> from[10001];
stack<char> s;

void init() {
	for (int i = 0; i < 10001; i++) {
		arr[i] = 0;
	}
	for (int i = 0; i < 10001; i++) {
		dist[i] = -1;
	}
	for (int i = 0; i < 10001; i++) {
		from[i].first = -1;
		from[i].second = 0;
	}
}

int calculate(int num, char op) {
	switch (op) {
		case 'D':
			num = num * 2 % 10000;
			break;
		case 'S':
			num = (num == 0) ? 9999 : num - 1;
			break;
		case 'L':
			num = (num * 10 % 10000) + (num / 1000);
			break;
		case 'R':
			num = (num / 10) + (num % 10 * 1000);
			break;
	}
	return num;
}

void bfs(int src, int dest) {
	char dx[4] = { 'D', 'S', 'L', 'R' };
	string answer;
	queue<int> q;
	q.push(src);
	dist[src] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = calculate(x, dx[i]);

			if (dist[nx] == -1) {
				q.push(nx);
				dist[nx] = dist[x] + 1;

				// 반대로 저장해서 역추적에 이용
				from[nx].first = x;
				from[nx].second = dx[i];

				if (nx == dest) {
					return;
				}
			}
		}
	}
}

void print_command(int src, int dest) {
	while (from[dest].first != src) {
		s.push(from[dest].second);
		dest = from[dest].first;
	}
	s.push(from[dest].second);

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, a, b;
	cin >> t;
	while (t--) {
		init();
		cin >> a >> b;
		bfs(a, b);
		print_command(a, b);
	}
	return 0;
}