#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        long long lo = 0, hi = 0;

        int red[n];
        for (int j = 0; j < n; j++) {
            cin >> red[j];
        }

        for (int j = 0; j < n; j++) {
            int blue;
            cin >> blue;
            long long oldLo = lo;
            lo = min(lo - red[j], blue - hi);
            hi = max(hi - red[j], blue - oldLo);
        }

        cout << hi << endl;
    }
}