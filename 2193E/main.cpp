#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<int> ans(n + 1, 1e9);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ans[a.at(i)] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                ans[j] = min(ans[j], ans[i] + ans[j / i]);
            }
        }
 
        for (int i = 1; i <= n; i++) cout << (ans[i] == 1e9 ? -1 : ans.at(i)) << " ";
        cout << endl;
    }
 
    return 0;
}