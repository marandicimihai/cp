#include <iostream>
#include <string>
using namespace std;

int fib[11] = { 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            int w, l, h;
            cin >> w >> l >> h;

            if (w >= fib[n-1] && l >= fib[n-1] && h >= fib[n-1] && max(max(w, l), h) >= fib[n]) {
                cout << 1;
            } else {
                cout << 0;
            }
        }

        cout << endl;
    }
}
