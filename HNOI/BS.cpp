#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MAXN = 1e6;
const string FNAME = "BS";

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen((FNAME + ".inp").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  ll n, x;
  cin >> n >> x;

  ll res = 0;

  for (int i = 1; i <= n; ++i) {
    if (i * (ll)(x/i) == x && x/i <= n) {
      ++res;
    }
  }

  cout << res;
  cerr << res;

  return 0;
}
