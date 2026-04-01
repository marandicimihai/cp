#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int cnt = 0;
        vector<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.back() >= a[i]) {
                st.pop_back();
            }

            if (st.empty() || st.back() != a[i] - 1) {
                cnt++;
                st.clear();
            }

            st.push_back(a[i]);
        }

        cout << cnt << endl;
    }
    
    return 0;
}
