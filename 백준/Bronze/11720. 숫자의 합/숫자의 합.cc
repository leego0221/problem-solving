#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n, sum = 0;
	string str;
	cin >> n >> str;
	for (int i = 0; i < n; i++) {
		int num = str.at(i) - '0';
		sum += num;
	}
	cout << sum << endl;
	return 0;
}