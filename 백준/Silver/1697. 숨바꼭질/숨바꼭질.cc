#include <iostream>
#include <queue>
using namespace std;

bool visited[100'001];
int line[100'001];
int line_dist[100'001];

void bfs(int src, int dest) {
	int dx[3] = { 1, -1, 0 }; // 0은 2*x
	queue<int> q;
	q.push(src);
	visited[src] = true;
	line_dist[src] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			int nx = (dx[i] != 0) ? (x + dx[i]) : (x * 2);
			if (nx < 0 || nx > 100'000) {
				continue;
			}
			if (!visited[nx]) {
				q.push(nx);
				visited[nx] = true;
				line_dist[nx] = line_dist[x] + 1;
				if (nx == dest) {
					return;
				}
			}
		}
	}
}

int main(void) {
	int n, k;
	cin >> n >> k;
	bfs(n, k);
	cout << line_dist[k];
	return 0;
}