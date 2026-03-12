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
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        
        int k = -1;
        for (int i = 0; i < n; i++) {
            int first = -1, last = -1;
            for (int j = 1; j < n; j++) {
                cout << a[j - 1] << " " << a[j] << endl;
                if (a[j - 1] > a[j]) {
                    cout << "bingo" << endl;
                    if (first == -1) first = a[j - 1];
                    last = a[j];
                    int temp = a[j - 1];
                    a[j - 1] = a[j];
                    a[j] = temp;
                }
                else {
                    k = max(k, abs(first - last));
                    first = -1; last = -1;
                }
            }
            k = max(k, abs(first - last));
            cout << first << " " << last << endl;
        }

        cout << (k == 0 ? -1 : k) << endl;
    }
 
    return 0;
}