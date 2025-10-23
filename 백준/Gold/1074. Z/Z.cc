#include <iostream>
#include <cmath>
using namespace std;

int n, r, c;
int ans;

void visit_array(int row, int col, int size) {
	if (row == r && col == c) {
		cout << ans;
		return;
	}

	if (r >= row && c >= col && r < row + size && c < col + size) {
		visit_array(row, col, size / 2);
		visit_array(row, col + size / 2, size / 2);
		visit_array(row + size / 2, col, size / 2);
		visit_array(row + size / 2, col + size / 2, size / 2);
	}
	else {
		ans += size * size;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> r >> c;
	visit_array(0, 0, pow(2, n));
	return 0;
}