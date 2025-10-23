#include <iostream>
using namespace std;

int main(void) {
	int t;
	string word;
	cin >> t;
	while (t--) {
		cin >> word;
		cout << word.front() << word.back() << '\n';
	}
	return 0;
}