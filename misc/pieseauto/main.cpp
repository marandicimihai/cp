#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int p = n * m, r = n;
    p += r / k * m;
    r %= k;
    
    cout << p;
}