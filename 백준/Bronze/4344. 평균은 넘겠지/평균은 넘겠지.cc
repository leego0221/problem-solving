#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int c, n;
	cin >> c;
	cout << fixed;
	cout.precision(3);

	for (int i = 0; i < c; i++) {
		double sum = 0, average = 0;
		int cnt = 0;
		cin >> n;
		double* score = new double[n];

		for (int j = 0; j < n; j++) {
			cin >> score[j];
			sum += score[j];
		}
		average = sum / n;
		for (int j = 0; j < n; j++) {
			if (average < score[j])
				cnt++;
		}

		cout << (double)cnt / n * 100 << '%' << endl;
		delete[] score;
	}
	return 0;
}