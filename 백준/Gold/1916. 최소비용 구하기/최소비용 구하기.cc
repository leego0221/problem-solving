#include <iostream>
#include <vector>
#include <queue>
#define INF ((1 << 31) - 1)
using namespace std;

vector<pair<int, int>> graph[1001];
int dist[1001];

struct compare {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};

void init_dist(int vertex) {
	for (int i = 1; i <= vertex; i++) {
		dist[i] = INF;
	}
}

void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
	pq.push(make_pair(start, 0));
	dist[start] = 0;

	while (!pq.empty()) {
		int current = pq.top().first;
		int distance = pq.top().second;
		pq.pop();

		if (dist[current] < distance) {
			continue;
		}

		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i].first;
			int next_dist = distance + graph[current][i].second;
			if (next_dist < dist[next]) {
				pq.push(make_pair(next, next_dist));
				dist[next] = next_dist;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, src, dest, bus_cost;
    
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> src >> dest >> bus_cost;
		graph[src].push_back(make_pair(dest, bus_cost));
	}
	cin >> src >> dest;

	init_dist(n);
	dijkstra(src);
	cout << dist[dest];
	return 0;
}