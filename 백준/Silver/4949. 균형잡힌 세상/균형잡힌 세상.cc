#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string str;
	bool is_balanced;
	while (1) {
		is_balanced = true;
		stack<char> stack;
		cin.ignore();
		getline(cin, str, '.');
		if (str.empty()) {
			break;
		}

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(') {
				stack.push('(');
			}
			else if (str[i] == ')') {
				if (stack.empty()) {
					is_balanced = false;
					break;
				}
				else if (stack.top() == '(') {
					stack.pop();
				}
				else {
					is_balanced = false;
					break;
				}
			}
			else if (str[i] == '{') {
				stack.push('{');
			}
			else if (str[i] == '}') {
				if (stack.empty()) {
					is_balanced = false;
					break;
				}
				else if (stack.top() == '{') {
					stack.pop();
				}
				else {
					is_balanced = false;
					break;
				}
			}
			else if (str[i] == '[') {
				stack.push('[');
			}
			else if (str[i] == ']') {
				if (stack.empty()) {
					is_balanced = false;
					break;
				}
				else if (stack.top() == '[') {
					stack.pop();
				}
				else {
					is_balanced = false;
					break;
				}
			}
		}
		if (!stack.empty()) is_balanced = false;

		cout << (is_balanced ? "yes" : "no") << "\n";
	}
	return 0;
}