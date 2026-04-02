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

    while(t--) {
        long long p, q;
        cin >> p >> q;

        if (q > p && min(p / 2, q / 3) >= q - p) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
    }
    
    return 0;
}
