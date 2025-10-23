#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> tree[100'001];
bool visited[100'001];
int dist[100'001];
pair<int, int> max_node;

void init_visited(int v) {
	for (int i = 1; i <= v; i++) {
		visited[i] = false;
	}
}

void dfs(int start, int distance) {
	visited[start] = true;
	dist[start] = distance;
	max_node.second = max(max_node.second, distance);
	if (max_node.second == distance) {
		max_node.first = start;
	}

	for (int i = 0; i < tree[start].size(); i++) {
		int next = tree[start][i].first;
		int next_dist = distance + tree[start][i].second;
		if (!visited[next]) {
			dfs(next, next_dist);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int v, num, vertex, weight;

	cin >> v;
	for (int i = 0; i < v; i++) {
		cin >> num >> vertex;
		while (vertex != -1) {
			cin >> weight;
			tree[num].push_back(make_pair(vertex, weight));
			cin >> vertex;
		}
	}

	dfs(1, 0);
	init_visited(v);
	dfs(max_node.first, 0);
	cout << max_node.second;
	return 0;
}