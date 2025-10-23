#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

int line[100'001];
int dist[100'001];

struct compare {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};

void dijkstra(int start) {
	int dx[3] = { -1, 1, 0 }; // 0은 2*x
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

		for (int i = 0; i < 3; i++) {
			int next = (dx[i] == 0) ? current * 2 : current + dx[i];
			int next_dist = (dx[i] == 0) ? distance : distance + 1;
			if (next < 0 || next > 100'000) {
				continue;
			}
			if (next_dist < dist[next]) {
				pq.push(make_pair(next, next_dist));
				dist[next] = next_dist;
			}
		}
	}
}

int main(void) {
	int n, k;
	cin >> n >> k;
	fill(dist, dist + 100'001, INT_MAX);
	dijkstra(n);
	cout << dist[k];
	return 0;
}