#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while(t--) {
        int k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;

        long long c = 0;
        long long kn = 1; // start at k^1
        while (kn <= r2) {
            long long lo = max((long long)l1, (l2 + kn - 1) / kn); // ceil(l2/kn)
            long long hi = min((long long)r1, r2 / kn);             // floor(r2/kn)
            if (hi >= lo) c += hi - lo + 1;
            if (kn > r2 / k) break; // overflow guard before multiplying
            kn *= k;
        }

        cout << c << endl;
    }

    return 0;
}
