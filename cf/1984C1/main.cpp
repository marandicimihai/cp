#include <iostream>
#include <string>
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
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        
        long long cmin = 0;
        long long cmax = 0;
        for (int i = 0; i < n; i++) {
            long long c = cmin;
            cmin = min(cmin + a[i], llabs(cmax + a[i]));
            cmax = max(cmax + a[i], llabs(c + a[i]));
        }

        cout << cmax << endl;
    }

    return 0;
}
