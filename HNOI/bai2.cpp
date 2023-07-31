#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "bai2";
const ll INF = 1e18 + 7;
//const int MAXN =;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".inp").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  ll a, b, k;
  cin >> a >> b >> k;

  ll res = INF;
  for (ll n = 0; n <= 18; ++n) {
    if ((a * (ll) pow(10, n + 2) + b) % (k - 10) == 0) {
      res = (a*pow(10, n + 2) + b) / (k - 10);
      break;
    }
  }

  cout << res;
  cerr << res;

  return 0;
}


