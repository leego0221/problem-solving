#include <iostream>
using namespace std;

int cnt[2][41];

void fibonacci(int n) {
    cnt[0][0] = 1, cnt[1][0] = 0;
    cnt[0][1] = 0, cnt[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        cnt[0][i] = cnt[0][i - 1] + cnt[0][i - 2];
        cnt[1][i] = cnt[1][i - 1] + cnt[1][i - 2];
    }
    cout << cnt[0][n] << " " << cnt[1][n] << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        fibonacci(n);
    }
    return 0;
}