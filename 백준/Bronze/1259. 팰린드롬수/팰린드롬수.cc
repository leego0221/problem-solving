#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int num, length;
	string str;
	bool is_pal;

	while (1) {
		is_pal = false;
		cin >> num;
		if (num == 0) break;
		
		str = to_string(num);
		length = str.length();
		if (length == 1) {
			is_pal = true;
		} else if (length == 2 || length == 3) {
			if (str[0] == str[length - 1]) {
				is_pal = true;
			}
		} else if (length == 4 || length == 5) {
			if (str[0] == str[length - 1] && str[1] == str[length - 2]) {
				is_pal = true;
			}
		}
		
		if (is_pal) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	}

	return 0;
}