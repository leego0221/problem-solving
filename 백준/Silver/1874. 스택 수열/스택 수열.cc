#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int arr[100'001];

int main(void) {
	int n, i, num = 1;
	stack<int> s;
	vector<char> v;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	i = 0;
	while (i < n) {
		if (s.empty()) {
			s.push(num++);
			v.push_back('+');
		}
		else if (arr[i] == s.top()) {
			s.pop();
			v.push_back('-');
			i++;
		}
		else {
			if (num > n) {
				cout << "NO";
				return 0;
			}
			s.push(num++);
			v.push_back('+');
		}
	}

	for (auto iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << '\n';
	}
	return 0;
}