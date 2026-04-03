#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <climits>
using namespace std;

int solve(int a, int b) {
    int dp[501][501];
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            if (i == j) {
                dp[i][j] = 0;
            } else {
                for (int k = 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                }
                for (int k = 1; k < i; k++) {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                }
            }
        }
    }

    return dp[a][b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b;
    cin >> a >> b;

    cout << solve(a, b);
    
    return 0;
}
