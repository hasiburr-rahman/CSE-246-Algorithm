#include <bits/stdc++.h>
using namespace std;

int main() {
    int s;
    cout << "Enter the Amount to be paid $- " << endl;
    cin >> s;

    int arr[6] = {50, 20, 10, 5, 2, 1};
    
    sort(arr, arr + 6);
    reverse(arr, arr + 6);

    int i = 0;
    int num;

    while (s > 0 && i < 6) {
        if (s >= arr[i]) {
            num = s / arr[i];
            s = s - (num * arr[i]);
            cout << num << " coins of " << arr[i] << " needed" << endl;
        } else {
            i++;
        }
    }

    return 0;
}
