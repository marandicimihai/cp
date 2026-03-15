#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ct;
    cin >> ct;
    while (ct--) {
        string s, t;
        cin >> s >> t;

        bool flag = true;
        for (int i = 0; i < (int)s.size(); i++) {
            size_t pos = t.find(s[i]);
            if (pos != string::npos) {
                t.erase(pos, 1);
            } else {
                flag = false;
            }
        }

        if (!flag) cout << "Impossible" << endl;
        else {
            sort(t.begin(), t.end());
    
            int i = 0, j = 0;
            while(j < (int)t.size() && i < (int)s.size()) {
                if ((int)s[i] <= (int)t[j]) {
                    t.insert(j, 1, s[i]);
                    i++;
                }
                j++;
            }
    
            if (i < (int)s.size()) {
                t.insert(t.size(), s.substr(i));
            }
    
            cout << t << endl;
        }
    }
}
