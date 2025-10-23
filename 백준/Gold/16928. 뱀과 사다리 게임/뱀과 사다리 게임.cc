#include <iostream>
#include <queue>
using namespace std;

int n, m;
int dist[101];
int board[101];

void bfs(int start) {
	int dx[6] = { 1, 2, 3, 4, 5, 6 }; // 주사위 눈
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) { // 주사위 수만큼 반복
			int nx = x + dx[i]; // 주사위 눈
			if (nx > 100) {
				continue;
			}
			nx = board[nx]; // 사다리 혹은 뱀을 구별하기 위함
			if (dist[nx] == -1) {
				q.push(nx);
				dist[nx] = dist[x] + 1;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int x, y, u, v;
	cin >> n >> m;
	for (int i = 1; i <= 100; i++) {
		board[i] = i; // 일반 칸은 자기 자신을 가리키게 함
		dist[i] = -1; // 이렇게 초기화해야 초반에 0이 유효함
	}
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		board[x] = y; // 사다리일 경우 board 갱신
	}
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		board[u] = v; // 뱀일 경우 board 갱신
	}

	bfs(1);
	cout << dist[100];
	return 0;
}