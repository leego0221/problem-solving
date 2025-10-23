#include <iostream>
using namespace std;

bool is_palindrome(string& str) {
	int length = str.length();
	for (int i = 0; i < length / 2; i++) {
		if (str[i] != str[length - i - 1]) {
			return false;
		}
	}
	return true;
}

int main(void) {
	string str;
	cin >> str;
	cout << is_palindrome(str);
	return 0;
}