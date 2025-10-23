#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int visited[101];
vector<int> graph[5001];

void init_visited() {
	for (int i = 0; i < 101; i++) {
		visited[i] = 0;
	}
}

int bfs(int from, int to) {
	queue<int> q;
	q.push(from);
	visited[from] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = visited[x] + 1;
			}
			if (y == to) {
				return visited[y];
			}
		}
	}
	return 0;
}

int main(void) {
	int n, m, u, v, degree;
	vector<pair<int, int>> kevin_bacon;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		degree = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				continue;
			}
			degree += bfs(i, j);
			init_visited();
		}
		kevin_bacon.push_back(make_pair(degree, i));
	}
	sort(kevin_bacon.begin(), kevin_bacon.end());

	cout << kevin_bacon[0].second;
	return 0;
}