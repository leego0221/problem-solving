#include <iostream>
#include <algorithm>
#define INF 1'000'000'000
using namespace std;

int dist[101][101];

void floyd_warshall(int num) {
	for (int k = 1; k <= num; k++) {
		for (int i = 1; i <= num; i++) {
			for (int j = 1; j <= num; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, a, b, c;
	cin >> n >> m;

	// dist[][] 채워넣기
	for (int i = 1; i <= n; i++) {
		fill(dist[i] + 1, dist[i] + n + 1, INF);
		dist[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (dist[a][b] > c) {
			dist[a][b] = c;
		}
	}

	// 플로이드-워셜
	floyd_warshall(n);

	// 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF) {
				cout << 0 << ' ';
			}
			else {
				cout << dist[i][j] << ' ';
			}
		}
		cout << '\n';
	}
	return 0;
}