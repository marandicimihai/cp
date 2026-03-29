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

        long long pf[n], sf[n], v[n]; 
        pf[0] = (a[0] > 0 ? a[0] : 0);
        sf[n-1] = (a[n-1] < 0 ? -a[n-1] : 0);
        for (int i = 1; i < n; i++) {
            pf[i] = pf[i - 1];
            if (a[i] > 0) pf[i] += a[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            sf[i] = sf[i + 1];
            if (a[i] < 0) sf[i] -= a[i];
        }
        for (int i = 0; i < n; i++) v[i] = sf[i] + pf[i];
        
        cout << *max_element(v, v + n) << endl;
    }
    
    return 0;
}
