#include <iostream>
using namespace std;

int main(void) {
	string str;
	int idx;
	cin >> str >> idx;
	cout << str.at(idx - 1);
	return 0;
}