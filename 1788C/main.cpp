#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n % 2 == 0) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;

        int m = (n - 1) / 2;

        // First group: (1, 3m+3), (2, 3m+4), ..., (m, 4m+2)
        for (int i = 1; i <= m; i++) {
            cout << i << " " << (3 * m + 2 + i) << "\n";
        }

        // Second group: (m+1, 2m+2), (m+2, 2m+3), ..., (2m+1, 3m+2)
        for (int i = m + 1; i <= 2 * m + 1; i++) {
            cout << i << " " << (m + 1 + i) << "\n";
        }

    }

    return 0;
}
