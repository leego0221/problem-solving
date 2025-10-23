#include <iostream>
using namespace std;

int main(void) {
	int n, count = 1;
	int start = 1, end = 1, plus = 0;
	cin >> n;
	while (true) {
		if (n >= start && n <= end)
			break;
		start = end + 1;
		plus += 6;
		end += plus;
		count++;
	}
	cout << count;
	return 0;
}