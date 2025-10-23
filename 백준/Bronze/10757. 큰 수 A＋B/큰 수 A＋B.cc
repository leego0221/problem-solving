#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	stack<int> result;
	string str1, str2;
	cin >> str1 >> str2;
	int len1 = str1.length();
	int len2 = str2.length();
	int length;
	if (len1 > len2) {
		length = len1;
		str2.insert(0, len1 - len2, '0');
	}
	else if (len1 < len2) {
		length = len2;
		str1.insert(0, len2 - len1, '0');
	}
	else
		length = len1;

	int carry = 0;
	for (int i = length - 1; i >= 0; i--) {
		int a = str1.at(i) - '0';
		int b = str2.at(i) - '0';
		int temp = a + b;
		temp += carry;
		carry = 0;
		if (temp >= 10) {
			temp -= 10;
			carry++;
		}
		result.push(temp);
	}
	if (carry)
		result.push(carry);
	while (!result.empty()) {
		cout << result.top();
		result.pop();
	}
	return 0;
}