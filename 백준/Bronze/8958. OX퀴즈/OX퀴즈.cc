#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int* arr = new int[n];
	string result;

	for (int i = 0; i < n; i++) {
		int score = 0, sum = 0;
		cin >> result;
		for (int j = 0; j < result.size(); j++) {
			if (result[j] == 'O') {
				score++;
				sum += score;
			}
			else
				score = 0;
		}
		arr[i] = sum;
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
	delete[] arr;
	return 0;
}