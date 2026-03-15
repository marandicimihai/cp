#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, x; cin >> n >> x;
        vector<long long> a(n), b(n), c(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b [i] >> c[i];
        }

        for (int i = 0; i < n; i++) {
            x -= a[i] * (b[i] - 1);
        }

        if (x <= 0) {
            cout << 0;
        } else {
            long long m = a.at(0) * b.at(0) - c.at(0);
            for (int i = 1; i < n; i++) {
                m = max(m, a.at(i) * b.at(i) - c.at(i));
            }

            if (m <= 0) cout << -1;
            else cout << (x + m - 1) / m;
        }
        cout << endl;
    }

    return 0;
}
