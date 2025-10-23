#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[1001];
vector<int> graph[1001];

void init_visited_array() {
	for (int i = 0; i < 1001; i++) {
		visited[i] = false;
	}
}

void dfs(int start) {
	visited[start] = true;
	cout << start << ' ';

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;
	cout << start << ' ';

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
				cout << y << ' ';
			}
		}
	}
}

int main(void) {
	int n, m, v, a, b;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	// 오름차순으로 정점을 탐색하기 위함
	for (int i = 0; i < 1001; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(v);
	cout << '\n';
	init_visited_array();
	bfs(v);
	return 0;
}