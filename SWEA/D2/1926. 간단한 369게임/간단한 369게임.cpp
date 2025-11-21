#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string result = "";
		int temp, num = i;
		for (int j = 100; j >= 1; j /= 10) {
			temp = num / j;
			if (temp == 3 || temp == 6 || temp == 9) {
				result += "-";
			}
			num = num - temp * j;
		}
		if (result.length() > 0) {
			cout << result << ' ';
		}
		else {
			cout << i << ' ';
		}
	}

	return 0;
}