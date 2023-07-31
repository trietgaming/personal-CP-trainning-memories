#include <bits/stdc++.h>

using namespace std;

const string FNAME = "madeup";
const int MAXN = 1e5;

int a[MAXN + 1], b[MAXN + 1], c[MAXN + 1];

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".ans").c_str(), "w", stdout);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
  }

  int res = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (a[i] == b[c[j]]) ++res;
    }
  }

  cout << res;

  return 0;
}


