#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	for (int i = 4; i <= n; i += 4) {
		cout << "long ";
	}
	cout << "int";
	return 0;
}