#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(void) {
	int count = 0;
	string str;
	getline(cin, str);
	stringstream ss(str);

	string stringBuffer;
	while (ss >> stringBuffer)
		count++;
	cout << count << endl;
	return 0;
}