#include <bits/stdc++.h>

using namespace std;

int main() {

  int n, res = 0;
  bool a, b, c;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b >> c;
    if (a && b || a && c || b && c)
      ++res;
  }

  cout << res;

  return 0;
}
