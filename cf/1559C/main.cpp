#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> adj[2 * n + 2];
        for (int i = 1; i <= n; i++) {
            adj[i].push_back(i + 1);
        }

        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;

            if (i == n) adj[i].clear();

            if (a == 0) {
                adj[i].push_back(n + 1);
            } else {
                adj[n + 1].push_back(i);
            }
        }

        if (find(adj[n].begin(), adj[n].end(), n + 1) != adj[n].end()) { // When last road is towards last element
            for (int i = 1; i <= n + 1; i++) {
                cout << i << " ";
            }
            cout << endl;
        } else if (find(adj[n + 1].begin(), adj[n + 1].end(), 1) != adj[n + 1].end()) { // When there is road from last element to first
            cout << n + 1 << " ";
            for (int i = 1; i <= n; i++) {
                cout << i << " ";
            }
            cout << endl;
        } else { // Have to look for 2 consequent roads i -> n + 1 -> i + 1
            for (int i = 1; i <= n - 1; i++) {
                if (find(adj[i].begin(), adj[i].end(), n + 1) != adj[i].end() && // i -> n + 1
                    find(adj[n + 1].begin(), adj[n + 1].end(), i + 1) != adj[n + 1].end()) { // n + 1 -> i + 1
                        for (int j = 1; j <= i; j++) {
                            cout << j << " ";
                        }
                        cout << n + 1 << " ";
                        for (int j = i + 1; j <= n; j++) {
                            cout << j << " ";
                        }
                        cout << endl;
                        break;
                    }
            }
        }

        // for (int i = 1; i <= 2 * n - 1; i++) {
        //     for (int a : adj[i]) {
        //         cout << i << " " << a << '\n';   // edge i -> a
        //     }
        // }
        // cout << "End case" << endl;
    }
    
    return 0;
}
