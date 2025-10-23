#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> tree[10'001];
bool visited[10'001];
int target_parent, tmp, max_value;
vector<int> radius;

bool compare(int a, int b) {
	return a > b;
}

void init_visited(int n) {
	for (int i = 1; i <= n; i++) {
		visited[i] = false;
	}
}

void dfs(int start) {
	visited[start] = true;

	for (int i = 0; i < tree[start].size(); i++) {
		int next = tree[start][i].first;
		int dist = tree[start][i].second;
		if (!visited[next]) {
			tmp += dist;
			max_value = max(max_value, tmp);

			dfs(next);

			tmp -= dist;
			if (start == target_parent) {
				radius.push_back(max_value);
				tmp = max_value = 0;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, u, v, w, diameter, ans = 0;

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v >> w;
		tree[u].push_back(make_pair(v, w));
	}

	for (int i = 1; i <= n; i++) {
		if (n == 1) {
			break;
		}
		if (tree[i].size() >= 2 || i == 1) {
			target_parent = i;
			init_visited(n);
			dfs(i);

			if (radius.size() == 1) {
				diameter = radius[0];
			}
			else {
				sort(radius.begin(), radius.end(), compare);
				diameter = radius[0] + radius[1];
			}
			ans = max(ans, diameter);

			radius.clear();
		}
	}
	cout << ans;
	return 0;
}