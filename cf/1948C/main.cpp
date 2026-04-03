#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;

int n;
vector<int> adj[400005];
bool visited[400005];
bool dfs(int s, int e) {
    if (visited[s]) return false;
    visited[s] = true;

    if (s == e) return true;

    bool cond = false;
    for (auto u : adj[s]) {
        cond = cond || dfs(u, e);
    }
    return cond;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while(t--) {
        cin >> n;
        string r1, r2;
        cin >> r1 >> r2;

        for (int i = 0; i < 2 * n; i++) {
            adj[i].clear();
            visited[i] = false;
        }
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (i < n - 1) { 
                    adj[i].push_back(i + 1);
                }
                if (i > 0) {
                    adj[i].push_back(i - 1);
                }
                adj[i].push_back(i + n);
            } else {
                if (r1[i] == '<') {
                    adj[i].push_back(i - 1);
                } else if (r1[i] == '>') {
                    adj[i].push_back(i + 1);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (i % 2 == 1) {
                if (i < n - 1) { 
                    adj[i + n].push_back(i + n + 1);
                }
                if (i > 0) {
                    adj[i + n].push_back(i + n - 1);
                }
                adj[i + n].push_back(i);
            } else {
                if (r2[i] == '<') {
                    adj[i + n].push_back(i + n - 1);
                } else if (r2[i] == '>') {
                    adj[i + n].push_back(i + n + 1);
                }
            }
        }

        cout << (dfs(0, 2 * n - 1) ? "YES" : "NO") << endl;
    }
    
    return 0;
}
