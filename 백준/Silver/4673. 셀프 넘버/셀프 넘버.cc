#include <iostream>
using namespace std;
int d(int num);

int main(void) {
	bool array[10001] = { false };
	for (int i = 1; i <= 10000; i++) {
		int n = d(i);
		if (n <= 10000)
			array[n] = true;
	}
	for (int i = 1; i <= 10000; i++)
		if (!array[i])
			cout << i << endl;
	return 0;
}

int d(int num) {
	int sum = num;
	while (num != 0) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}
