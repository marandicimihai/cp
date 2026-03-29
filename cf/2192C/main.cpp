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
        long long n, h, k;
        cin >> n >> h >> k;

        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];

        long long ps[n]; ps[0] = a[0];
        for (int i = 1; i < n; i++) ps[i] = ps[i - 1] + a[i];

        //for (int i = 0; i < n; i++) cout << ps[i] << " ";
        //cout << endl;

        long long v = 0;
        v += (h / ps[n - 1]) * (n + k); // required reloads
        h %= ps[n - 1];

        if (h == 0) {
            v -= k;
            cout << v << endl;
            continue;
        }

        long long b = lower_bound(ps, ps + n, h) - ps;
        long long j = *max_element(a + b, a + n);

        long long minL = LLONG_MAX;
        long long ans = b; // fallback: no swap helps
        for(int i = 0; i < b; i++){
            minL = min(minL, (long long)a[i]);
            if(ps[i] - minL + j >= h){
                ans = i;
                break;
            }
        }
        v += ans + 1;

        cout << v << endl;
    }
    
    return 0;
}
