#include <iostream>
#include <map>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	multimap<int, string> m;
	int age, n;
	string name;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> age >> name;
		m.insert(make_pair(age, name));
	}

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << " " << iter->second << "\n";
	}
	return 0;
}