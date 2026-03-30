#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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

        long long pf[n]; pf[0] = a[0];
        for (int i = 1; i < n; i++) pf[i] = pf[i - 1] + a[i];

        long long ans = pf[n - 1];
        for (int l = 0; l < n; l++) {
            int r = n - 1;
            while (l <= r) {
                long long displacedSum = pf[r] - pf[l] + a[l];
                long long replacement = (l + r + 2) * (r - l + 1);

                long long gainNow = (l + r + 2) * (r - l + 1) - (pf[r] - pf[l] + a[l]);
                long long gainIfShrink = (l + r + 1) * (r - l) - (pf[r] - pf[l] + a[l]) - a[r];

                if (gainNow >= gainIfShrink) {
                    ans = max(ans, pf[n - 1] - displacedSum + replacement);
                } else {
                    break;
                }
                r--;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
