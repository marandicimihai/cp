#include <iostream>
#include <string>
#include <vector>
using namespace std;

string c2[2] = { "12", "21" };
string c3[6] = { "123", "132", "213", "231", "312", "321" };
string c4[24] = { "1234", "1243", "1324", "1342", "1423", "1432", "2134", "2143", "2314", "2341", "2413", "2431", "3124", "3142", "3214", "3241", "3412", "3421", "4123", "4132", "4213", "4231", "4312", "4321" };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, j, k;
        cin >> n >> j >> k;

        int c = 0;
        int ncopy = n;
        while (ncopy != 0) {
            ncopy /= 10;
            c++;
        }

        string s1, s2;
        if (c == 2) {
            s1 = c2[j - 1];
            s2 = c2[k - 1];
        } else if (c == 3) {
            s1 = c3[j - 1];
            s2 = c3[k - 1];
        } else {
            s1 = c4[j - 1];
            s2 = c4[k - 1];
        }
        
        int a = 0, b = 0;
        for (int i = 0; i < c; i++) {
            if (s1[i] == s2[i]) {
                a++;
            } else if (s2.find(s1[i]) != string::npos) {
                b++;
            }
        }

        cout << a << "A" << b << "B" << endl;
    }

    return 0;
}
