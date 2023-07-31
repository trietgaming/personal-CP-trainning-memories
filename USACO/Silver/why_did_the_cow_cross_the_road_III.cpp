#include <bits/stdc++.h>

using namespace std;

const string FNAME = "maxcross";
const int MAXN = 100000;

int totalBroken[MAXN + 1];
bool broken[MAXN + 1];

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, k, b;
  cin >> n >> k >> b;

  for (int i = 1; i <= b; ++i) {
    int pos;
    cin >> pos;
    broken[pos] = true;
  }

  for (int i = 1; i <= n; ++i) {
    totalBroken[i] = totalBroken[i-1];
    if (broken[i]) ++totalBroken[i];
  }

  int res = INT_MAX;

  for (int i = k; i <= n; ++i) {
    res = min(res, totalBroken[i] - totalBroken[i-k]);
  }

  cout << res;

  return 0;
}


