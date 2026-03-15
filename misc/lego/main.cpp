#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long a[3], b[3], K;
    for (int i = 0; i < 3; i++) cin >> a[i];
    for (int i = 0; i < 3; i++) cin >> b[i];
    cin >> K;
    
    // Sort so we iterate over the two smallest b values
    int idx[3] = {0, 1, 2};
    sort(idx, idx+3, [&](int i, int j){ return b[i] < b[j]; });
    long long a0=a[idx[0]], b0=b[idx[0]];
    long long a1=a[idx[1]], b1=b[idx[1]];
    long long a2=a[idx[2]], b2=b[idx[2]];
    
    long long ans = K; // T=0 case
    
    for (long long c0 = 0; c0 <= b0; c0++) {
        for (long long c1 = 0; c1 <= b1; c1++) {
            long long rem = K - c0*a0 - c1*a1;
            // Greedy: best c2 such that c2*a2 is closest to rem
            long long c2 = (rem <= 0) ? 0 : min(rem / a2, b2);
            // Check floor and ceil candidates
            for (int dc = 0; dc <= 1; dc++) {
                long long c2t = c2 + dc;
                if (c2t <= b2) {
                    long long T = c0*a0 + c1*a1 + c2t*a2;
                    ans = min(ans, abs(T - K));
                }
            }
            if (ans == 0) { cout << 0 << "\n"; return 0; }
        }
    }
    
    cout << ans << "\n";
    return 0;
}