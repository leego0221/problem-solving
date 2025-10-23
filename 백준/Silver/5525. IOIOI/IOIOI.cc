#include <iostream>
using namespace std;

int table[1'000'001];

void make_table(string pattern) {
	int j = 0;
	for (int i = 1; i < pattern.size(); i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
}

int kmp(string parent, string pattern) {
	make_table(pattern);

	int j = 0, cnt = 0;
	for (int i = 0; i < parent.size(); i++) {
		while (j > 0 && parent[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (parent[i] == pattern[j]) {
			if (j == pattern.size() - 1) {
				j = table[j];
				cnt++;
			}
			else {
				j++;
			}
		}
	}
	return cnt;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, p_length, cnt = 0;
	string s, p = "IOI";

	cin >> n >> m >> s;
	for (int i = 1; i < n; i++) {
		p.append("OI");
	}

	cout << kmp(s, p);
	return 0;
}