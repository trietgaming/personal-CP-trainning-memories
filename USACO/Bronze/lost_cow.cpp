#include <bits/stdc++.h>

using namespace std;

int main() {

  freopen("lostcow.in", "r", stdin);
  freopen("lostcow.out", "w", stdout);

  int x, y;

  cin >> x >> y;

  int base = 1, res = 0, prevPos = x;

  if (x == y) {
    cout << 0;
  } else if (x < y) {
    while (x + base < y) {
      res += abs(x + base - prevPos);
      prevPos = x + base;
      base *= -2;
    }
    cout << res + abs(y - prevPos);
  } else {
    while (x + base > y) {
      res += abs(x + base - prevPos);
      prevPos = x + base;
      base *= -2;
    }
    cout << res + abs(y - prevPos);
  }
  return 0;
}
