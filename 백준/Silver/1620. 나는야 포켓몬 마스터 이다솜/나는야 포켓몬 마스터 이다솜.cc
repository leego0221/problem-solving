#include <iostream>
#include <map>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	string name, problem;
	map<int, string> pokemon1; // key가 숫자
	map<string, int> pokemon2; // key가 포켓몬
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> name;
		pokemon1.insert(make_pair(i, name));
		pokemon2.insert(make_pair(name, i));
	}

	for (int i = 0; i < m; i++) {
		cin >> problem;
		if (isdigit(problem[0])) { // 숫자
			cout << pokemon1.at(atoi(problem.c_str())) << '\n';
		}
		else { // 포켓몬
			cout << pokemon2.at(problem) << '\n';
		}
	}
	return 0;
}