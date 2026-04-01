#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int n;
vector<int> adj[200005];
long long dp[200005];
bool visited[200005];

int dfs(int s) {
    if (visited[s]) return 0;
    visited[s] = true;

    int sum = 0;
    for (auto u : adj[s]) {
        sum += dfs(u);
    }

    if (sum == 0) {
        return 1;
    } else {
        dp[s] = sum;
        return dp[s];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while(t--) {
        cin >> n;
        
        for (int i = 1; i <= n; i++) {
            dp[i] = 1;
            visited[i] = false;
            adj[i].clear();
        }

        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        dfs(1);

        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int x, y;
            cin >> x >> y;
            cout << dp[x] * dp[y] << endl;
        }
    }
    
    return 0;
}
