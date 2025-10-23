#include <iostream>
#include <vector>
using namespace std;

int parent[51];
bool know[51];
vector<int> party[51];

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
	int n, m, truth, person, num, cnt = 0;

	// 입력
	cin >> n >> m >> truth;
	for (int i = 0; i < truth; i++) {
		cin >> person;
		know[person] = true;
	}
	for (int i = 0; i < m; i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> person;
			party[i].push_back(person);
		}
	}

	// 집합 구성
	init_parent(n);
	for (int i = 0; i < m; i++) {
		if (party[i].size() >= 2) {
			for (int j = 0; j < party[i].size() - 1; j++) {
				union_parent(party[i][j], party[i][j + 1]);
			}
		}
	}

	// 진실을 알게 되는 사람 갱신
	for (int i = 1; i <= n; i++) {
		if (know[i]) {
			for (int j = 1; j <= n; j++) {
				if (!is_disjoint(i, j)) {
					know[j] = true;
				}
			}
		}
	}

	// 거짓말 가능한 파티 수 계산 후 출력
	for (int i = 0; i < m; i++) {
		if (!know[party[i][0]]) {
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}