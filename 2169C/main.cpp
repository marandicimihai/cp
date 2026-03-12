#include <iostream>
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
        vector<long long> a(n + 1);

        for (int i = 1; i <= n; i++) cin >> a[i];

        long long total = 0;
        for (int i = 1; i <= n; i++) total += a[i];

        long long best = 0;
        long long cur_sum = 0;
        int l = 1;

        for (int r = 1; r <= n; r++) {
            cur_sum += a[r];

            // Try shrinking from left
            while (l <= r) {
                long long gain_now =
                    (long long)(r - l + 1) * (l + r) - cur_sum;

                long long gain_if_shrink =
                    (long long)(r - (l + 1) + 1) * ((l + 1) + r)
                    - (cur_sum - a[l]);

                if (gain_if_shrink >= gain_now) {
                    cur_sum -= a[l];
                    l++;
                } else {
                    break;
                }
            }

            long long gain =
                (long long)(r - l + 1) * (l + r) - cur_sum;

            best = max(best, gain);
        }

        cout << total + best << "\n";
    }
}
