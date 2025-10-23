#include <iostream>
#include <string>
#include <set>
using namespace std;

struct compare {
	bool operator() (const string& left, const string& right) const {
		if (left.size() == right.size()) {
			return left < right; // size가 같으면 문자열 비교
		} else {
			return left.size() < right.size(); // size가 다르면 size 비교
		}
	}
};

int main(void) {
	int cnt;
	string word;
	set<string, compare> s;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> word;
		s.insert(word);
	}

	for (string str : s) {
		cout << str << "\n";
	}

	return 0;
}