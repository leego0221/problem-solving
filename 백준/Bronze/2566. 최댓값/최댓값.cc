#include <iostream>
using namespace std;

int arr[10][10];
int ans = -1, row = 1, col = 1; // 초기값 설정

int main(void) {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> arr[i][j];
			if (ans < arr[i][j]) {
				ans = arr[i][j];
				row = i;
				col = j;
			}
 		}
	}
	cout << ans << '\n' << row << ' ' << col;
	return 0;
}