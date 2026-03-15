#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;
        int a[n][m]; bool e[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                if (a[i][j] == 0) {
                    e[i][j] = true;
                } else {
                    e[i][j] = false;
                }
            }
        }

        queue<pair<int, int>> q;

        long long ans = 0;
        bool allExplored = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (e[i][j]) continue; // already explored or zero

                long long vol = 0;
                q.push({i, j});
                e[i][j] = true; // mark on push

                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();

                    vol += a[r][c];

                    if (r > 0 && !e[r - 1][c]) {
                        e[r - 1][c] = true;
                        q.push({r - 1, c});
                    }
                    if (r < n - 1 && !e[r + 1][c]) {
                        e[r + 1][c] = true;
                        q.push({r + 1, c});
                    }
                    if (c > 0 && !e[r][c - 1]) {
                        e[r][c - 1] = true;
                        q.push({r, c - 1});
                    }
                    if (c < m - 1 && !e[r][c + 1]) {
                        e[r][c + 1] = true;
                        q.push({r, c + 1});
                    }
                }

                ans = max(ans, vol);
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}
