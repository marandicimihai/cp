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

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<long long> prefAbs(n);
        vector<long long> suffix(n + 1, 0);

        // prefix of absolute values
        prefAbs[0] = a[0];
        for (int i = 1; i < n; i++)
            prefAbs[i] = prefAbs[i - 1] + llabs(a[i]);

        // suffix normal sums
        for (int i = n - 1; i >= 0; i--)
            suffix[i] = suffix[i + 1] + a[i];

        long long ans = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            long long cur;

            if (i == 0) {
                cur = -suffix[1];
            } else {
                long long middle = prefAbs[i - 1] - a[0];
                cur = a[0] + middle - suffix[i + 1];
            }

            ans = max(ans, cur);
        }

        cout << ans << "\n";
    }
}