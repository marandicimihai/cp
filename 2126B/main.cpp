#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k, h = 0, cnt = 0;
        cin >> n >> k;

        for (int i = 0; i < n; i++) {
            int w;
            cin >> w;

            if (w == 0) h++;
            else h = 0;

            if (h == k) {
                cnt++;
                h = -1;
            }
        }

        cout << cnt << endl;
    }
}
