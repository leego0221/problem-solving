#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int n, k;
int arr[100'001];
int dist[100'001];
int from[100'001];

int calc(int x, int op) {
	if (op == 0)
		return x - 1;
	else if (op == 1)
		return x + 1;
	else if (op == 2)
		return x * 2;
}

int bfs(int start) {
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	from[start] = n;
	if (start == k) {
		return dist[start];
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			int nx = calc(x, i);
			if (nx < 0 || nx > 100'000) {
				continue;
			}
			if (dist[nx] == -1) {
				q.push(nx);
				dist[nx] = dist[x] + 1;
				from[nx] = x;
				if (nx == k) {
					return dist[nx];
				}
			}
		}
	}
}

void traceback(int src, int dest) {
	stack<int> s;
	int tmp = dest;

	s.push(dest);
	while (from[tmp] != src) {
		s.push(from[tmp]);
		tmp = from[tmp];
	}
	if (src != dest) {
		s.push(src);
	}

	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	fill(dist, dist + 100'001, -1);
	cout << bfs(n) << '\n';
	traceback(n, k);
	return 0;
}