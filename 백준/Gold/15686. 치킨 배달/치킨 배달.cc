#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int city[51][51];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken_place;
pair<int, int> selected[15];
vector<int> ans;

int calc_dist(int r1, int c1, int r2, int c2) {
	int a = r1 > r2 ? r1 - r2 : r2 - r1;
	int b = c1 > c2 ? c1 - c2 : c2 - c1;
	return a + b;
}

void backtracking(int depth, int start) {
	// depth만큼 치킨집 정했으면 도시의 치킨 거리 계산 시작
	if (depth == m) {
		int total_distance = 0;
		// 각각의 집마다 치킨 거리를 구함
		for (auto iter = house.begin(); iter != house.end(); iter++) {
			int tmp = 1'000'000'000;
			// 하나의 집에 각각의 치킨집과의 거리를 계산 후 최솟값 구함
			for (int i = 0; i < m; i++) {
				int r1 = iter->first;
				int c1 = iter->second;
				int r2 = selected[i].first;
				int c2 = selected[i].second;
				tmp = min(tmp, calc_dist(r1, c1, r2, c2));
			}
			total_distance += tmp;
		}
		// 해당 경우일 때 도시의 치킨 거리의 최솟값 저장
		ans.push_back(total_distance);
		return;
	}

	for (int i = start; i < chicken_place.size(); i++) {
		int row = chicken_place[i].first;
		int col = chicken_place[i].second;
		selected[depth] = chicken_place[i];

		city[row][col] = 2; // 해당 위치를 치킨집으로 바꿈
		backtracking(depth + 1, i + 1); // 재귀 호출
		city[row][col] = 0; // 해당 위치를 빈칸으로 바꿈
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// 입력
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1) {
				house.push_back(make_pair(i, j)); // 집 위치 저장
			}
			else if (city[i][j] == 2) {
				chicken_place.push_back(make_pair(i, j)); // 치킨집 위치 저장
				city[i][j] = 0; // 일단 빈칸으로 바꿔줌
			}
		}
	}

	// 도시의 치킨 거리 구하기
	backtracking(0, 0);
	
	// 출력
	cout << *min_element(ans.begin(), ans.end());
	return 0;
}