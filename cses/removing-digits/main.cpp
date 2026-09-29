#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <set>
#include <map>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  long long d[1000001];
  long long n;
  cin >> n;

  for (int i = 1; i < 10; i++) {
    d[i] = 1;
  }
  for (int i = 10; i < 999999; i++) {
    d[i] = 99999999;
  }

  long long current = 10;
  while (current <= n) {

    long long minSteps = 99999999;
    long long currentCopy = current;
    while (currentCopy != 0) {
      long long digit = currentCopy % 10;
      currentCopy /= 10;
      if (d[current - digit] < minSteps) {
        minSteps = d[current - digit];
      }
    }

    d[current] = minSteps + 1;

    current++;
  }

  // for (int i = 0; i < current; i++) {
  //   cout << i << " " << d[i] << endl;
  // }

  cout << d[current - 1];
  
  return 0;
}
