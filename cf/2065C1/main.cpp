#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> b;

        int p = min(a[0], b - a[0]);
        bool possible = true;
        for (int i = 1; i < n; i++) {
            if (p > a[i] && p > b - a[i]) {
                possible = false;
                break;
            }
            
            if (p <= a[i] && p <= b - a[i])     p = min(a[i], b - a[i]);
            else if (p <= b - a[i])             p = b - a[i];
            else                                p = a[i];
        }

        cout << (possible ? "YES" : "NO") << endl;
    }
}
