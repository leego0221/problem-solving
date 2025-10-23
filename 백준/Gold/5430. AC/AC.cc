#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, n;
	string function, array;

	cin >> t;
	while (t--) {
		deque<int> d;
		string str;
		bool is_reversed = false, is_error = false;
		cin >> function >> n;
		cin >> array;

		for (int i = 1; i < array.size(); i++) {
			if (array[i] == ',' || array[i] == ']') {
				if (str.size() == 0) {
					continue;
				}
				d.push_back(stoi(str));
				str.clear();
				continue;
			}
			str.push_back(array[i]);
		}

		for (int i = 0; i < function.size(); i++) {
			if (function[i] == 'R') {
				is_reversed = !is_reversed;
			}
			else if (function[i] == 'D') {
				if (d.size() == 0) {
					is_error = true;
					break;
				}
				is_reversed ? d.pop_back() : d.pop_front();
			}
		}

		if (is_error) {
			cout << "error\n";
		}
		else {
			cout << '[';
			if (d.size() == 0) {
				cout << "]\n";
			}
			else if (is_reversed) {
				for (auto riter = d.rbegin(); riter != d.rend(); riter++) {
					cout << *riter << (riter == d.rend() - 1 ? "]\n" : ",");
				}
			}
			else {
				for (auto iter = d.begin(); iter != d.end(); iter++) {
					cout << *iter << (iter == d.end() - 1 ? "]\n" : ",");
				}
			}
		}
	}
	return 0;
}