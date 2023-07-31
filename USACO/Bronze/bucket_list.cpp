#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int arr[MAXN + 1];

int main() {

  freopen("blist.in", "r", stdin);
  freopen("blist.out", "w", stdout);

  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    int s, e, b;
    cin >> s >> e >> b;
    arr[s] += b;
    arr[e] -= b;
  }

  int res = 0, current = 0;

  for (int i = 1; i <= MAXN; ++i) {
      res = max(res, current += arr[i]);
  }

  cout << res;

  return 0;
}
