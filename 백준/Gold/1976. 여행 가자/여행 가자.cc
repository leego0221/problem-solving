#include <iostream>
using namespace std;

int graph[202][202];
int parent[202];
int city[1001];

void init_parent(int n) {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}

int find_parent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = find_parent(parent[x]);
}

void union_parent(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

bool is_disjoint(int a, int b) {
	return find_parent(a) != find_parent(b);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;

	// 입력
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> city[i];
	}
	
	// parent[] 구성
	init_parent(n);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (graph[i][j] == 1) {
				union_parent(i, j);
			}
		}
	}

	// 집합 포함 여부 확인 후 출력
	for (int i = 1; i <= m - 1; i++) {
		if (is_disjoint(city[i], city[i + 1])) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}