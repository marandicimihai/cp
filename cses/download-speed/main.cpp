#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <set>
#include <map>
using namespace std;

int n, m;
vector<pair<int, int>> adj[505];
vector<int> l;

void dfs(int s, int e, int x) {
    if (s == e) {
        l.push_back(x);
        return;
    }

    for (auto u : adj[s]) {
        dfs(u.first, e, min(x, u.second));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    dfs(1, n, INT_MAX);

    for (auto u : l) {
        cout << u << " ";
    }
    
    return 0;
}
