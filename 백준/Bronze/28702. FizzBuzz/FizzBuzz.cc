#include <iostream>
#include <string>
using namespace std;

int num;

int main(void) {
	string str[3];
	for (int i = 0; i < 3; i++) {
		cin >> str[i];
	}
	for (int i = 0; i < 3; i++) {
		if (str[i][0] != 'F' && str[i][0] != 'B') {
			num = stoi(str[i]) + 3 - i;
			break;
		}
	}

	if (num % 15 == 0) {
		cout << "FizzBuzz";
	}
	else if (num % 3 == 0 && num % 5 != 0) {
		cout << "Fizz";
	}
	else if (num % 3 != 0 && num % 5 == 0) {
		cout << "Buzz";
	}
	else {
		cout << num;
	}
	return 0;
}