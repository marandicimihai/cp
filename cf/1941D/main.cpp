#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int n, m, x;
int r[1005];
char c[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while(t--) {
        cin >> n >> m >> x;
        for (int i = 0; i < m; i++) {
            cin >> r[i] >> c[i];
        }
        set<int> q;
        q.insert(x);

        for (int i = 0; i < m; i++) {
            set<int> nq;
            for (int u : q) {
                int cw = (u - 1 + r[i]) % n + 1;
                int ccw = (u - 1 - r[i] + n) % n + 1;
                if (c[i] != '1') nq.insert(cw);
                if (c[i] != '0') nq.insert(ccw);
            }
            q.swap(nq);
        }

        cout << q.size() << '\n';
        bool first = true;
        for (int v : q) {
            if (!first) {
                cout << ' ';
            }
            cout << v;
            first = false;
        }
        cout << '\n';
    }
    
    return 0;
}
