#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[100'001];
bool visited[100'001];
int parent[100'001];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			int y = graph[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
				parent[y] = x; // 각 노드의 부모를 저장
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, u, v;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	bfs(1);
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}
	return 0;
}