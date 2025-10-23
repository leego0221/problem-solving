#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

const int INF = numeric_limits<int>::max();
vector<pair<int, int>> graph[1001];
int dist[1001];
int from[1001]; // 백트래킹을 위한 배열

struct compare {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};

int dijkstra(int src, int dest) {
	fill(dist, dist + 1001, INF);
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
				from[next] = current; // 백트래킹의 초석을 마련
			}
		}
	}
	return dist[dest];
}

void traceback(int dest, int src) {
	stack<int> s;
	int tmp = dest;
	s.push(dest);
	while (from[tmp] != src) {
		s.push(from[tmp]);
		tmp = from[tmp];
	}
	s.push(from[tmp]);

	// 도시 개수 출력
	cout << s.size() << '\n';

	// 도시 순서대로 출력
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, src, dest, cost;

	// 입력
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> src >> dest >> cost;
		graph[src].push_back(make_pair(dest, cost));
	}
	cin >> src >> dest;

	// 최소비용 계산 및 출력
	cout << dijkstra(src, dest) << '\n';
	traceback(dest, src);
	return 0;
}