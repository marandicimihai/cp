#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
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
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        // Check if all elements are divisible by k
        bool possible = true;
        for (auto& p : cnt) {
            if (p.second % k != 0) {
                possible = false;
                break;
            }
        }

        if (!possible) {
            cout << 0 << endl;
            continue;
        }

        long long ans = 0;
        map<int, int> c;  // count in current subarray
        int r = 0;

        for (int l = 0; l < n; l++) {
            // Expand r as far as possible while condition is satisfied
            while (r < n) {
                c[a[r]]++;
                
                // Check if adding a[r] violates the condition
                if (c[a[r]] > cnt[a[r]] / k) {
                    c[a[r]]--;
                    break;
                }
                r++;
            }
            
            // All subarrays [l, l], [l, l+1], ..., [l, r-1] are valid
            ans += r - l;
            
            // Move l forward
            c[a[l]]--;
            if (c[a[l]] == 0) {
                c.erase(a[l]);
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}
