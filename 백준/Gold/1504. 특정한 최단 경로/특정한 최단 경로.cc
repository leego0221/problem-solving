#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <queue>
using namespace std;

int INF = numeric_limits<int>::max();
vector<pair<int, int>> graph[808];
int dist[808];

struct compare {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};

int dijkstra(int src, int dest) {
	fill(dist, dist + 808, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
	pq.push(make_pair(src, 0));
	dist[src] = 0;

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
	return dist[dest];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, e, a, b, c, v1, v2, path[5] = { 0, };

	// 입력
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	cin >> v1 >> v2;

	// 구간별로 최단 경로 구하기
	path[0] = dijkstra(1, v1);
	path[1] = dijkstra(1, v2);
	path[2] = dijkstra(v1, v2);
	path[3] = dijkstra(v1, n);
	path[4] = dijkstra(v2, n);

	// 출력
	for (int i = 0; i < 5; i++) {
		if (path[i] == INF) {
			cout << -1;
			return 0;
		}
	}
	cout << min(path[0] + path[2] + path[4], path[1] + path[2] + path[3]);
	return 0;
}