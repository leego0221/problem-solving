#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n, count = 0;
	string str;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;
		bool isCorrect = true;
		for (int j = 0; j < str.size() - 1; j++) {
			int left = j, right = str.size() - 1;
			char leftWord = str.at(left), rightWord;
			while (left < right) {
				rightWord = str.at(right);
				if (leftWord == rightWord)
					break;
				right--;
			}

			int idx = left + 1;
			while (idx < right) {
				if (str.at(idx) == str.at(right))
					idx++;
				else {
					isCorrect = false;
					break;
				}
			}
			if (!isCorrect)
				break;
		}
		isCorrect ? count++ : count;
	}
	cout << count << endl;
	return 0;
}