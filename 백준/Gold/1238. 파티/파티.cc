#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <queue>
using namespace std;

int INF = numeric_limits<int>::max();
vector<pair<int, int>> graph[2][1001];
int dist[2][1001];

void dijkstra(int type, int x) {
	fill(dist[type], dist[type] + 1001, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, x));
	dist[type][x] = 0;

	while (!pq.empty()) {
		int distance = pq.top().first;
		int current = pq.top().second;
		pq.pop();
		if (dist[type][current] < distance) {
			continue;
		}

		for (int i = 0; i < graph[type][current].size(); i++) {
			int next_dist = distance + graph[type][current][i].first;
			int next = graph[type][current][i].second;
			if (next_dist < dist[type][next]) {
				pq.push(make_pair(next_dist, next));
				dist[type][next] = next_dist;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, x, u, v, w;
	
	// 입력
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		graph[0][u].push_back(make_pair(w, v)); // 정방향 그래프
		graph[1][v].push_back(make_pair(w, u)); // 역방향 그래프
	}

	// 최단 경로 계산
	dijkstra(0, x); // X -> 학생들
	dijkstra(1, x); // 학생들 -> X

	// 출력
	for (int i = 1; i <= n; i++) {
		dist[0][i] += dist[1][i];
	}
	cout << *max_element(dist[0] + 1, dist[0] + n + 1);
	return 0;
}