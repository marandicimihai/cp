#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

int dsu[200000];

int find(int x) {
    if (dsu[x] != x)
        dsu[x] = find(dsu[x]);
    return dsu[x];
}

int union_(int x, int y) {
    dsu[find(x)] = find(y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        string s;
        cin >> s;
        for (int i = 0; i < n; i++) dsu[i] = i;

        for (int i = 0; i < n; i++) {
            union_(i, a[i] - 1);
        }

        map<int, vector<int>> groups;
        for (int i = 0; i < n; i++)
            groups[find(dsu[i])].push_back(i);

        map<int, int> nums;
        for (auto& [root, members] : groups) {
            int cnt = 0;
            for (int x : members) {
                if (s[x] == '0') {
                    cnt++;
                }
            }
            nums[root] = cnt;
        }

        for (int i = 0; i < n; i++) {
            cout << nums[find(dsu[i])] << " ";
        }

        cout << endl;
    }

    return 0;
}
