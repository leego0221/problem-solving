#include <iostream>
#include <algorithm>
#define INF 1'000'000'000
using namespace std;

int dist[101][101];
int item[101];
int result[101];

void floyd_warshall(int num) {
	for (int k = 1; k <= num; k++) {
		for (int i = 1; i <= num; i++) {
			for (int j = 1; j <= num; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, r, a, b, l;
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> item[i];
	}

	// dist[][] 초기 설정
	for (int i = 1; i <= n; i++) {
		fill(dist[i] + 1, dist[i] + n + 1, INF);
		dist[i][i] = 0;
	}
	for (int i = 0; i < r; i++) {
		cin >> a >> b >> l;
		dist[a][b] = l;
		dist[b][a] = l;
	}

	// 플로이드-워셜
	floyd_warshall(n);

	// 결과 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] <= m) {
				result[i] += item[j];
			}
		}
	}
	cout << *max_element(result + 1, result + n + 1);
	return 0;
}