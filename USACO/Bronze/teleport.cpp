#include <bits/stdc++.h>

using namespace std;

int main() {

  freopen("teleport.in", "r", stdin);
  freopen("teleport.out", "w", stdout);

  int from, to, teleX, teleY;
  cin >> from >> to >> teleX >> teleY;

  int shortestFrom = min(abs(from - teleX), abs(from - teleY));
  int shortestTo = min(abs(to - teleX), abs(to - teleY));

  cout << min(abs(to - from), shortestFrom + shortestTo);

  return 0;
}
