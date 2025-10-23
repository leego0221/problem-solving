#include <iostream>
using namespace std;

int n;
bool g[101][101];

void floyd_warshall() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (g[i][k] == true && g[k][j] == true) {
					g[i][j] = true;
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
		}
	}

	// 플로이드-워셜
	floyd_warshall();

	// 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << g[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}