#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        if (k == n * n - 1) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cnt < k) {
                    cout << 'U';
                    cnt++;
                } else if (j == n - 1 && i == n - 1) {
                    cout << 'L';
                } else if (i == n - 1) {
                    cout << 'R';
                } else {
                    cout << 'D';
                }
            }
            cout << endl;
        }
    }

    return 0;
}
