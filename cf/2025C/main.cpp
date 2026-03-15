#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        
        vector<int> b;
        int bi = 0;
        int last = a[0];
        b.push_back(1);
        for (int i = 1; i < n; i++) {
            if (a[i] == last) {
                b[bi]++;
            } else {
                if (abs(a[i] - last) > 1) {
                    b.push_back(0);
                    bi++;
                }
                b.push_back(1);
                bi++;
            }
            last = a[i];
        }

        int m = b.size();
        vector<int> pre(m + 1, 0);
        for (int i = 0; i < m; i++) pre[i+1] = pre[i] + b[i];

        int ans = 0;
        int last_zero = -1;
        for (int r = 0; r < m; r++) {
            if (b[r] == 0) {
                last_zero = r;
            } else {
                int l = max(r - k + 1, last_zero + 1);
                if (r - l + 1 <= k) {  // window has exactly k elements
                    int sum = pre[r+1] - pre[l];
                    ans = max(ans, sum);
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
