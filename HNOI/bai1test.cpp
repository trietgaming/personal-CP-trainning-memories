#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "bai1";
const int INF = 1e9 + 7;
//const int MAXN =;
long long res = 5, n;

ll sum_range(ll a, ll b) {
  return (b - a + 1) * (b + a) / 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".inp").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n;

  for (ll i = 0; i <= n; ++i) {
    for (ll j = 0; j <= i; ++j) {
      if (sum_range(j, i) == n)
        {
          ++res;
          cerr << j << " " << i << endl;
        }
    }
  }

  cout << res;
  cerr << res;

  return 0;
}


