#include <iostream>
#include <vector>
using namespace std;

int x = 0;
int y = 0;

string dir = "right";
void goRight() {
    if (dir == "right") {
        dir = "down";
    } else if (dir == "down") {
        dir = "left";
    } else if (dir == "left") {
        dir = "up";
    } else if (dir == "up") {
        dir = "right";
    }
}

void goBack1() {
    if (dir == "right") {
        x -= 1;
    } else if (dir == "down") {
        y -= 1;
    } else if (dir == "left") {
        x += 1;
    } else if (dir == "up") {
        y += 1;
    }
}

void goForward1() {
    if (dir == "right") {
        x += 1;
    } else if (dir == "down") {
        y += 1;
    } else if (dir == "left") {
        x -= 1;
    } else if (dir == "up") {
        y -= 1;
    }
}

int main() {
    int nsq, n;
    cin >> nsq;
    n = sqrt(nsq);

    vector<int> v(nsq);
    int m[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = -1;
        }
    }

    for (int i = 0; i < nsq; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end(), greater<int>());

    int min = v[0], max = v[0];
    cout << 4 * n - 4 << " ";
    for (int i = 1; i < 4 * n - 4; i++) {
        if (min > v[i]) min = v[i];
        if (max < v[i]) max = v[i];
    }
    cout << min << " " << max << endl;

    for (int i = 0; i < nsq; i++) {
        if (m[y][x] != -1) {
            goBack1();
            goRight();
            goForward1();
        } 
        m[y][x] = v[i];
        goForward1();
        if (dir == "right" && x == n || dir == "down" && y == n || dir == "left" && x == -1 || dir == "up" && y == -1) {
            goBack1();
            goRight();
            goForward1();
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}