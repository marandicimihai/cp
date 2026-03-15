#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, k;
int a[200000];
int r[200000][2];
int d[200000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) d[i] = -1;
    d[1] = 0;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        r[i][0] = min(x, y);
        r[i][1] = max(x, y);
    }

    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < m; i++) {
            int u = r[i][0], v = r[i][1];
            if (d[u] != -1 && (d[v] == -1 || d[v] > d[u] + 1)) {
                d[v] = d[u] + 1;
                changed = true;
            }
            if (d[v] != -1 && (d[u] == -1 || d[u] > d[v] + 1)) {
                d[u] = d[v] + 1;
                changed = true;
            }
        }
    }

    for (int i = 1; i <= k; i++) {
        int best = -1;
        for (int j = 1; j <= n; j++) {
            if (a[j] == i) {
                best = max(best, d[j]);
            }
        }
        cout << best << " ";
    }
    cout << endl;

    return 0;
}
