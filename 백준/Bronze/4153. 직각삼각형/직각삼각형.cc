#include <iostream>
#include <algorithm>
using namespace std;

int arr[3];

int main(void) {
    while (1) {
        cin >> arr[0] >> arr[1] >> arr[2];
        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) {
            break;
        }

        sort(arr, arr + 3);
        int left = arr[2] * arr[2];
        int right = arr[0] * arr[0] + arr[1] * arr[1];

        if (left == right) {
            cout << "right" << "\n";
        } else {
            cout << "wrong" << "\n";
        }
    }

    return 0;
}