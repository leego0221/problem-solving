#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int t, r;
	string s;
	cin >> t;
	for (int n = 0; n < t; n++) {
		cin >> r >> s;
		for (int i = 0; i < s.size(); i++)
			for (int j = 0; j < r; j++)
				cout << s.at(i);
		cout << endl;
	}
	return 0;
}