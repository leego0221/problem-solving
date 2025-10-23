#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int count = 0;
	string str;
	cin >> str;
	str = str + ".."; // OutOfBounds 방지
	
	for (int i = 0; i < str.size(); i++) {
		if (str.at(i) == '.')
			break;
		if (str.at(i) == 'c' && str.at(i + 1) == '=') {
			i++, count++;
			continue;
		}
		if (str.at(i) == 'c' && str.at(i + 1) == '-') {
			i++, count++;
			continue;
		}
		if (str.at(i) == 'd' && str.at(i + 1) == 'z' && str.at(i + 2) == '=') {
			i += 2, count++;
			continue;
		}
		if (str.at(i) == 'd' && str.at(i + 1) == '-') {
			i++, count++;
			continue;
		}
		if (str.at(i) == 'l' && str.at(i + 1) == 'j') {
			i++, count++;
			continue;
		}
		if (str.at(i) == 'n' && str.at(i + 1) == 'j') {
			i++, count++;
			continue;
		}
		if (str.at(i) == 's' && str.at(i + 1) == '=') {
			i++, count++;
			continue;
		}
		if (str.at(i) == 'z' && str.at(i + 1) == '=') {
			i++, count++;
			continue;
		}
		count++;
	}
	cout << count << endl;
	return 0;
}