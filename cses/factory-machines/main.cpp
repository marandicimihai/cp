#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;

unsigned long long n, t;
vector<int> k(200005);
bool check(unsigned long long time) {
    unsigned long long s = 0;
    for (int i = 0; i < n; i++) {
        s += (time / k[i]);
        if (s >= t) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> k[i];
    unsigned long long maxT = *min_element(k.begin(), k.begin() + n) * t;

    unsigned long long lo = 0, hi = maxT;
    while (lo < hi) {
        unsigned long long mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo;
    
    return 0;
}
