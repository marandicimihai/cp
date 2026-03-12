#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const long long MOD = 998244353;

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) res = res * i % MOD;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        int a[n], b[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

    }

    return 0;
}
