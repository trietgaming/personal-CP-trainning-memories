#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e7;
const string FNAME = "CP";

bool sieve[MAXN];

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen((FNAME + ".inp").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  ll a, b;
  cin >> a >> b;

  ll res = 0;

  for (ll i = 2; i < MAXN && i * i <= b; ++i) {
    if (sieve[i]) continue;
    if (i * i >= a) ++res;
    for (ll j = i * i; j < MAXN && j <= b; j += i) {
      sieve[j] = true;
    }
  }

  cout << res;
  cerr << res;

  return 0;
}
