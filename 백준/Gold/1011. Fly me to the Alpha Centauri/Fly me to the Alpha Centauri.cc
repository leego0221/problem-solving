#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, x, y;
	cin >> t;
	while (t--) {
		cin >> x >> y;
		cout << ceil(2 * sqrt(y - x) - 1) << '\n';
	}
	return 0;
}