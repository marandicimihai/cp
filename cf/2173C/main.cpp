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
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        a.erase(std::unique(a.begin(), a.end()), a.end());

        vector<bool> used(a.size(), false); 
        vector<int> B;
        bool ok = true;
        
        for (int i = 0; i < (int)a.size() && ok; i++) {
            if (used[i]) continue;

            int x = a[i];

            // check all multiples of x up to k
            for (int val = 2 * x; val <= k; val += x) {
                auto it = lower_bound(a.begin(), a.end(), val);

                if (it == a.end() || *it != val) {
                    // required multiple missing
                    ok = false;
                    break;
                }

                int idx = it - a.begin();
                used[idx] = true;
            }

            B.push_back(x);
            used[i] = true;
        }


        if (!ok) {
            cout << -1 << '\n';
        } else {
            cout << B.size() << '\n';
            for (int x : B) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
