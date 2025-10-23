#include <iostream>
using namespace std;

int s;
string n;

void print_part1() {
	for (int i = 0; i < n.length(); i++) {
		switch (n[i]) {
		case '1':
		case '4':
			cout << ' ';
			for (int j = 0; j < s; j++) {
				cout << ' ';
			}
			cout << "  ";
			break;
		case '2':
		case '3':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '0':
			cout << ' ';
			for (int j = 0; j < s; j++) {
				cout << '-';
			}
			cout << "  ";
			break;
		}
	}
	cout << '\n';
}

void print_part2() {
	for (int repeat = 0; repeat < s; repeat++) {
		for (int i = 0; i < n.length(); i++) {
			switch (n[i]) {
			case '1':
			case '2':
			case '3':
			case '7':
				cout << ' ';
				for (int j = 0; j < s; j++) {
					cout << ' ';
				}
				cout << "| ";
				break;
			case '4':
			case '8':
			case '9':
			case '0':
				cout << '|';
				for (int j = 0; j < s; j++) {
					cout << ' ';
				}
				cout << "| ";
				break;
			case '5':
			case '6':
				cout << '|';
				for (int j = 0; j < s; j++) {
					cout << ' ';
				}
				cout << "  ";
				break;
			}
		}
		cout << '\n';
	}
}

void print_part3() {
	for (int i = 0; i < n.length(); i++) {
		switch (n[i]) {
		case '1':
		case '7':
		case '0':
			cout << ' ';
			for (int j = 0; j < s; j++) {
				cout << ' ';
			}
			cout << "  ";
			break;
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '8':
		case '9':
			cout << ' ';
			for (int j = 0; j < s; j++) {
				cout << '-';
			}
			cout << "  ";
			break;
		}
	}
	cout << '\n';
}

void print_part4() {
	for (int repeat = 0; repeat < s; repeat++) {
		for (int i = 0; i < n.length(); i++) {
			switch (n[i]) {
			case '1':
			case '3':
			case '4':
			case '5':
			case '7':
			case '9':
				cout << ' ';
				for (int j = 0; j < s; j++) {
					cout << ' ';
				}
				cout << "| ";
				break;
			case '2':
				cout << '|';
				for (int j = 0; j < s; j++) {
					cout << ' ';
				}
				cout << "  ";
				break;
			case '6':
			case '8':
			case '0':
				cout << '|';
				for (int j = 0; j < s; j++) {
					cout << ' ';
				}
				cout << "| ";
				break;
			}
		}
		cout << '\n';
	}
}

void print_part5() {
	for (int i = 0; i < n.length(); i++) {
		switch (n[i]) {
		case '1':
		case '4':
		case '7':
			cout << ' ';
			for (int j = 0; j < s; j++) {
				cout << ' ';
			}
			cout << "  ";
			break;
		case '2':
		case '3':
		case '5':
		case '6':
		case '8':
		case '9':
		case '0':
			cout << ' ';
			for (int j = 0; j < s; j++) {
				cout << '-';
			}
			cout << "  ";
			break;
		}
	}
	cout << '\n';
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> s >> n;
	print_part1();
	print_part2();
	print_part3();
	print_part4();
	print_part5();
	return 0;
}