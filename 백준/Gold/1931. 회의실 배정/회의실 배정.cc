#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, start, end, cnt = 0;
	vector<pair<int, int>> meetings;
	pair<int, int> curr = make_pair(0, 0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		meetings.push_back(make_pair(start, end));
	}
	sort(meetings.begin(), meetings.end(), compare);

	for (int i = 0; i < meetings.size(); i++) {
		if (curr.second <= meetings[i].first) {
			curr = meetings[i];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}