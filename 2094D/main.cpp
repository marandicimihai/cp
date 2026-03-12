#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string p, s;
        cin >> p >> s;

        int si = 0, pi = 0;
        char lp = p[0];
        char ls = s[0];
        
        bool flag = true;
        if (ls == lp) {
            for (int i = 0; i < p.length(); i++) {
                int scnt = 1, pcnt = 1;
                while (++pi < p.length()) {
                    if (lp != p[pi]) {
                        lp = p[pi];
                        break;
                    }
                    pcnt++;
                    lp = p[pi];
                }
                while (++si < s.length()) {
                    if (ls != s[si]) {
                        ls = s[si];
                        break;
                    }
                    scnt++;
                    ls = s[si];
                }
                if (scnt > 2 * pcnt || scnt < pcnt || (pi >= p.length() && si < s.length()) || (pi < p.length() && si >= s.length())) {
                    flag = false;
                }
                // cout << pi << " " << si << endl;
            }
        } else flag = false;

        cout << (flag ? "YES" : "NO") << endl;
    }
}
