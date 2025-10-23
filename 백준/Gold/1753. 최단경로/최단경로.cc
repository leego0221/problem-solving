#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> graph[20'002];
int dist[20'002];

// 초기값은 모두 INF로 설정
void init_dist(int vertex) {
	for (int i = 1; i <= vertex; i++) {
		// 가중치가 10 이하라고 해서 INF값을 낮게 잡으면 안 됨
		dist[i] = INT_MAX;
	}
}

// pair<int, int>의 second를 중심으로 오름차순 정렬
struct compare {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};

// 우선순위 큐를 이용한 다익스트라 알고리즘
void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
	pq.push(make_pair(start, 0));
	dist[start] = 0;

	while (!pq.empty()) {
		int current = pq.top().first;
		int distance = pq.top().second;
		pq.pop();

		// 갱신된 최소 경로보다 더 길기 때문에 무시해주고 넘어감
		if (dist[current] < distance) {
			continue;
		}

		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i].first;
			int next_dist = distance + graph[current][i].second;
			if (dist[next] > next_dist) {
				pq.push(make_pair(next, next_dist));
				dist[next] = next_dist;
 			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int vertex, edge, k, u, v, w;

	// 입력
	cin >> vertex >> edge >> k;
	for (int i = 0; i < edge; i++) {
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	// dist[] 초기화 후 다익스트라 알고리즘 수행
	init_dist(vertex);
	dijkstra(k);

	// 출력
	for (int i = 1; i <= vertex; i++) {
		if (dist[i] == INT_MAX) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << '\n';
		}
	}
	return 0;
}