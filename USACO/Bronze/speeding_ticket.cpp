#include <bits/stdc++.h>

using namespace std;

int road[100], journey[100];

int main() {

  freopen("speeding.in", "r", stdin);
  freopen("speeding.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  for (int i = 0, last = 0, segment, limit; i < n; ++i) {
    cin >> segment >> limit;
    for (int j = last; j < segment + last; ++j) {
      road[j] = limit;
    }
    last += segment;
  }

  for (int i = 0, last = 0, segment, limit; i < m; ++i) {
    cin >> segment >> limit;
    for (int j = last; j < segment + last; ++j) {
      journey[j] = limit;
    }
    last += segment;
  }

  int res = 0;

  for (int i = 0; i < 100; ++i) {
   res = max(res, journey[i] - road[i]);
  }

  cout << res;


  return 0;
}
