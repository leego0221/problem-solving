#include <iostream>
#include <map>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	string site, passwd;
	map<string, string> map;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> site >> passwd;
		map.insert(make_pair(site, passwd));
	}
	for (int i = 0; i < m; i++) {
		cin >> site;
		cout << map.at(site) << '\n';
	}
	return 0;
}