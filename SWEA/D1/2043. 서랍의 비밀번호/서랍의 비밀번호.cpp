#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int p, k;
	cin >> p >> k;
	cout << p - k + 1 << '\n';

	return 0;
}