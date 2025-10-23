#include <iostream>
#include <vector>
using namespace std;

int cnt;
bool visited[101];
vector<int> graph[101];

void dfs(int start, vector<int> graph[], bool visited[]) {
	visited[start] = true;
	cnt++;

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		if (visited[next] == false) {
			dfs(next, graph, visited);
		}
	}
}

int main(void) {
	int n, edge, a, b;
	cin >> n >> edge;
	for (int i = 0; i < edge; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1, graph, visited);
	cout << --cnt;
	return 0;
}