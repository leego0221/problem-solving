
#include <iostream>
#include <cmath>
using namespace std;

int input[11];

int main(int argc, char** argv)
{
	int tc;
	int T;
	cin >> T;
	for (tc = 1; tc <= T; ++tc)
	{
		int sum = 0;
		for (int i = 0; i < 10; i++) {
			cin >> input[i];
			sum += input[i];
		}
		int result = round((double)sum / 10);

		cout << '#' << tc << ' ' << result << '\n';
	}

	return 0;
}