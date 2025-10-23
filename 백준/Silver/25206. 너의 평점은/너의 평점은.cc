#include <iostream>
#define PASS 5.0
using namespace std;

double calc_grade(string grade) {
	double res = 0;
	if (!grade.compare("A+")) {
		res = 4.5;
	} else if (!grade.compare("A0")) {
		res = 4.0;
	} else if (!grade.compare("B+")) {
		res = 3.5;
	} else if (!grade.compare("B0")) {
		res = 3.0;
	} else if (!grade.compare("C+")) {
		res = 2.5;
	} else if (!grade.compare("C0")) {
		res = 2.0;
	} else if (!grade.compare("D+")) {
		res = 1.5;
	} else if (!grade.compare("D0")) {
		res = 1.0;
	} else if (!grade.compare("F")) {
		res = 0.0;
	} else if (!grade.compare("P")) {
		res = PASS;
	}
	return res;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string subject, grade;
	double credit, sum1 = 0, sum2 = 0, res = 0, tmp;

	for (int i = 0; i < 20; i++) {
		cin >> subject >> credit >> grade;
		tmp = calc_grade(grade);
		if (tmp == PASS) {
			continue;
		}
		sum1 += credit * tmp;
		sum2 += credit;
	}

	cout << sum1 / sum2;
	return 0;
}