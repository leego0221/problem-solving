#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	int tc;
	int T;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		string str, result;
		int num[3] = { 0 };
		cin >> str;

		num[0] = stoi(str.substr(0, 4));
		num[1] = stoi(str.substr(4, 2));
		num[2] = stoi(str.substr(6, 2));
		result = str.substr(0, 4) + "/" + str.substr(4, 2) + "/" + str.substr(6, 2);

		switch (num[1]) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (num[2] < 1 || num[2] > 31) {
				result = "-1";
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (num[2] < 1 || num[2] > 31) {
				result = "-1";
			}
			break;
		case 2:
			if (num[2] < 1 || num[2] > 28) {
				result = "-1";
			}
			break;
		default:
			result = "-1";
		}

		cout << '#' << tc << ' ' << result << '\n';
	}

	return 0;
}