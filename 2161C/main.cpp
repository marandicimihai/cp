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

    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n), ans;
        for (int i = 0; i < n; i++) cin >> a[i];

        sort(a.begin(), a.end());
        int ptr1 = 0, ptr2 = a.size() - 1;
        long long s = 0;
        long long p = 0;
        
        while (ptr1 <= ptr2) {
            if (s / x < (s + a.at(ptr2)) / x) {
                p += a.at(ptr2);
                s += a.at(ptr2);
                ans.push_back(a.at(ptr2));
                ptr2--;
            } else {
                s += a.at(ptr1);
                ans.push_back(a.at(ptr1));
                ptr1++;
            }
        }

        cout << p << endl;
        for (int i = 0; i < n; i++) cout << ans.at(i) << " ";
        cout << endl;
    }

    return 0;
}
