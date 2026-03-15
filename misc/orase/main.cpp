#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n, c1, c2;
    cin >> n >> c1 >> c2;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    int k = 1;
    long long s[n + 1];
    for (int i = 1; i <= n; i++) s[i] = LLONG_MIN;
    s[1] = a[1];
    while (k < n) {
        // Verificam orasele in care poate zbura
        for (int t = k + 1; t <= n; t++) {
            if (t % k == 0) {
                s[t] = max(s[t], s[k] + a[t] - c2 * (t / k));
            }
        }
        s[k + 1] = max(s[k + 1], s[k] + a[k + 1] - c1);
        k++;
    }
    
    cout << s[n];

    return 0;
}