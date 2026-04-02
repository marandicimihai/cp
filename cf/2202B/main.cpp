#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        string x;
        cin >> x;

        if (n % 2 == 1 && x[0] == 'b') {
            cout << "NO" << endl;
            continue;
        }

        bool good = true;
        if (n % 2 == 0) {
            for (int i = 0; i + 1 < n; i += 2) {
                if (x[i] != '?' && x[i + 1] != '?' && x[i] == x[i + 1]) {
                    good = false;
                    break;
                }
            }
        } else {
            for (int i = 1; i + 1 < n; i += 2) {
                if (x[i] != '?' && x[i + 1] != '?' && x[i] == x[i + 1]) {
                    good = false;
                    break;
                }
            }
        }

        cout << (good ? "YES" : "NO") << endl;
    }
    
    return 0;
}
