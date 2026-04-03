#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
using namespace std;

int cnt = 0;
bool occupied[8][8];
bool c[8], d1[15], d2[15];

void search(int y) {
    if (y == 8) {
        cnt++;
        return;
    }

    for (int x = 0; x < 8; x++) {
        if (c[x] || d1[x + y] || d2[x - y + 7] || occupied[y][x]) continue;
        c[x] = 1; d1[x + y] = 1; d2[x - y + 7] = 1;
        search(y+1);
        c[x] = 0; d1[x + y] = 0; d2[x - y + 7] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i < 8; i++) {
        string x;
        cin >> x;
        for (int j = 0; j < 8; j++) {
            if (x[j] == '*') {
                occupied[i][j] = true;
            } else {
                occupied[i][j] = false;
            }
        }
    }

    search(0);

    cout << cnt;
    
    return 0;
}
