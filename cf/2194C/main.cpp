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

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<string> strips(k);
        for (int i = 0; i < k; i++) {
            cin >> strips[i];
        }

        string answer = "";

        // We need MINIMUM informativity => smallest valid divisor d
        for (int d = 1; d <= n; d++) {
            if (n % d != 0) continue;

            bool good = true;
            string period = "";

            for (int z = 0; z < d; z++) { // residue class modulo d
                int possible = (1 << 26) - 1; // letters that can still work for this class

                for (int pos = z; pos < n; pos += d) {
                    int here = 0; // letters available at this position among all strips
                    for (int j = 0; j < k; j++) {
                        here |= (1 << (strips[j][pos] - 'a'));
                    }
                    possible &= here;
                }

                if (possible == 0) {
                    good = false;
                    break;
                }

                // pick one valid letter (lexicographically smallest)
                for (int b = 0; b < 26; b++) {
                    if (possible & (1 << b)) {
                        period.push_back(char('a' + b));
                        break;
                    }
                }
            }

            if (good) {
                // build full message of length n by repeating period
                for (int rep = 0; rep < n / d; rep++) {
                    answer += period;
                }
                break; // first valid d is minimal
            }
        }

        cout << answer << '\n';
    }
    
    return 0;
}