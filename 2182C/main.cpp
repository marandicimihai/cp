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
        int n;
        cin >> n;
        int a[n], b[n], c[n];

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];

        long long nr1 = 0, nr2 = 0;
        for (int j = 0; j < n; j++) {
            bool flag1 = true, flag2 = true;
            for (int i = 0; i < n; i++) {
                if (b[i] <= a[(i + j) % n]) flag1 = false;
            }
            for (int i = 0; i < n; i++) {
                if (c[i] <= b[(i + j) % n]) flag2 = false;
            }

            if (flag1) nr1++;
            if (flag2) nr2++;
        }

        cout << n * nr1 * nr2 << endl;
    }
}