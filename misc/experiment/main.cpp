#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    bool flag = true;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] != 1) {
            flag = false;
        }
    }

    if (flag) {
        cout << "DA" << endl << a[n - 1];
    } else {
        int count = 0;
        for (int i = 0; i < n; i++) {
            bool left  = (i == 0     || a[i] != a[i-1]);
            bool right = (i == n - 1 || a[i] != a[i+1]);
            if (left && right) count++;
        }
        cout << "NU" << endl << count;
    }

    return 0;
}