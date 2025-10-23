#include <iostream>
using namespace std;

int main(void) {
	int num, temp, newNum, count = 0;
	cin >> num;
	temp = num;
	while (true) {
		count++;
		newNum = (temp / 10) + (temp % 10);
		newNum = (temp % 10) * 10 + (newNum % 10);
		if (num == newNum)
			break;
		temp = newNum;
	}
	cout << count << endl;
	return 0;
}