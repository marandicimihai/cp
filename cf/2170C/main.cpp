#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
// unsolved
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> q(n), r(n);
        for (int i = 0; i < n; i++) cin >> q[i];
        for (int i = 0; i < n; i++) cin >> r[i];

        int c = 0;
        bool flag = false;
        while (!flag) {
            flag = true;
            for (int x = 2; x <= k; x++) {
                for (int y = 1; y < x; y++) {
                    auto qi = find(q.begin(), q.end(), x / y);
                    auto rj = find(r.begin(), r.end(), x % y);
                    if (qi != q.end() && rj != r.end()) {
                        cout << *qi << " " << *rj << endl;
                        q.erase(qi);
                        r.erase(rj);
                        c++;
                        flag = false;
                    }
                }
            }
        }

        cout << c << endl;
    }

    return 0;
}
