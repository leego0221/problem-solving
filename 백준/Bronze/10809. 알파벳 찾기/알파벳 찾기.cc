#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int check[26];
	for (int i = 0; i < 26; i++)
		check[i] = -1;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		int idx = s.at(i) - 'a';
		if (check[idx] == -1)
			check[idx] = i;
	}
	for (int i = 0; i < 26; i++)
		cout << check[i] << ' ';
	return 0;
}