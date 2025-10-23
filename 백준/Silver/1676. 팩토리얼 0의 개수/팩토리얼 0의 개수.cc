#include <iostream>
using namespace std;

int main(void) {
	int n, res = 1, cnt = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		res *= i; // 팩토리얼 구하는 과정
		while (res % 10 == 0) { // 맨 끝자리가 0이면
			res /= 10; // 0 하나 제거
			res %= 1000; // 불필요한 앞부분 제거(한 번에 0이 3개 생기는 순간이 있음)
			cnt++; // 0 개수 세기
		}
		res %= 10000; // 0 구한 뒤 일정 앞부분을 날려버림
	}

	cout << cnt;
	return 0;
}