#include <iostream>
#include <string>
#include <climits>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        long long r[n], l[n];

        l[0] = 0;
        l[1] = 1;
        int x = 2;
        while (x < n) {
            long long lf = abs(a[x - 1] - a[x - 2]);
            long long rg = abs(a[x - 1] - a[x]);
            if (lf == 0) lf = LLONG_MAX;
            if (rg == 0) rg = LLONG_MAX;
            l[x] = l[x - 1] + (rg < lf ? 1 : rg);
            x++;
        }

        r[n - 1] = 0;
        r[n - 2] = 1;
        int y = n - 3;
        while (y >= 0) {
            long long rg = abs(a[y + 1] - a[y + 2]);
            long long lf = abs(a[y + 1] - a[y]);
            if (lf == 0) lf = LLONG_MAX;
            if (rg == 0) rg = LLONG_MAX;
            r[y] = r[y + 1] + (rg > lf ? 1 : lf);
            y--;
        }

        int m;
        cin >> m;
        while (m--) {
            int x, y;
            cin >> x >> y;
           
            if (x < y) {
                cout << l[y - 1] - l[x - 1];
            } else {
                cout << r[y - 1] - r[x - 1];
            }
            cout << endl;
        }
    }

    return 0;
}
