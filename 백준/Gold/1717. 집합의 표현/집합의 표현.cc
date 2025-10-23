#include <iostream>
using namespace std;

int parent[1'000'001];

void init_parent(int n) {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}

int get_parent(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = get_parent(parent[x]);
}

void union_parent(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

bool find_parent(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);
	return a == b;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, op, a, b;
	cin >> n >> m;

	init_parent(n);
	for (int i = 0; i < m; i++) {
		cin >> op >> a >> b;
		if (op == 0) {
			union_parent(a, b);
		}
		else if (op == 1) {
			if (find_parent(a, b)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
	return 0;
}