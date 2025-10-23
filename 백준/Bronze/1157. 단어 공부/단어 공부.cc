#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int check[26] = { 0 };
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		int temp = str.at(i) - 'A';
		if (temp > 25)
			temp -= 32;
		check[temp]++;
	}

	int max = 0, front, back;
	for (int i = 0; i < 26; i++)
		if (max < check[i]) {
			max = check[i];
			front = i;
		}
	for (int i = 25; i >= 0; i--)
		if (max == check[i]) {
			back = i;
			break;
		}

	if (front != back)
		cout << '?' << endl;
	else {
		char c = front + 'A';
		cout << c << endl;
	}
	return 0;
}