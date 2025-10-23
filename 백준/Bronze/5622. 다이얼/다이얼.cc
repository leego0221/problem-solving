#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int sum = 0;
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		char ch = str.at(i);
		if (ch >= 'A' && ch <= 'C')
			sum += 3;
		else if (ch >= 'D' && ch <= 'F')
			sum += 4;
		else if (ch >= 'G' && ch <= 'I')
			sum += 5;
		else if (ch >= 'J' && ch <= 'L')
			sum += 6;
		else if (ch >= 'M' && ch <= 'O')
			sum += 7;
		else if (ch >= 'P' && ch <= 'S')
			sum += 8;
		else if (ch >= 'T' && ch <= 'V')
			sum += 9;
		else if (ch >= 'W' && ch <= 'Z')
			sum += 10;
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
			sum += 11;
	}
	cout << sum << endl;
	return 0;
}