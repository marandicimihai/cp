#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string g[n];
        bool flag3 = false;
        for (int i = 0; i < n; i++) {
            cin >> g[i];
            for (int j = 0; j < m; j++) {

                if (g[i][j] == '0' || flag3) continue;

                bool flag = false;
                for (int z = 0; z < i; z++) {
                    if (g[z][j] == '0') {
                        flag = true;
                    }
                }

                for (int z = 0; z < j; z++) {
                    if (g[i][z] == '0') {
                        flag3 = flag;
                    }
                }
            }
        }

        if (flag3) {
            cout << "NO";
        } else {
            cout << "YES";
        }

        cout << endl;
    }
}
