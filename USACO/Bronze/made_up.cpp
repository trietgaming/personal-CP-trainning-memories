#include <bits/stdc++.h>

using namespace std;

const string FNAME = "madeup";
const int MAXN = 100003;

int bExists[MAXN + 1];
int a[MAXN + 1], b[MAXN + 1], c[MAXN + 1];

int main() {

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

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
    bExists[b[c[i]]]++;
  }

  long long res = 0;

  for (int i = 1; i <= n; ++i) {
    res += bExists[a[i]];
  }

  cout << res;

  return 0;
}


