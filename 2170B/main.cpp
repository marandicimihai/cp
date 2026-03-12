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
        int n;
        cin >> n;
        long long c = 0, s = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x > 0) {
                c++;
            }
            s += x;
        }

        long long s2 = s - c;
        long long sub = n - 1 - s2;
        cout << c - max(0ll, sub) << endl;
    }

    return 0;
}
