#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "";
const int MAXN = 1e6+1, MOD = 1e9+7;

ll perms[MAXN];
ll feq[256];

ll bin_pow(ll base, ll _exp) {
  if (_exp == 0) return 1;
  ll res = bin_pow(base, _exp / 2);
  res = (res * res) % MOD;
  if (_exp & 1) {
    res = (res * base) % MOD;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  string s;
  cin >> s;
  int n = s.size();

  fill(feq, feq + 256, 0);
  perms[0] = 1;
  for (int i = 1; i <= n; ++i) {
    perms[i] = (perms[i - 1] * i) % MOD;
    ++feq[s[i-1]];
  }

  ll res = perms[n];
  for (int i = 'a'; i <= 'z'; ++i) {
    res *= bin_pow(perms[feq[i]], MOD - 2);
//    assert((bin_pow(perms[feq[i]], MOD - 2) * perms[feq[i]]) % MOD == 1);
    res %= MOD;
  }
//  cout << bin_pow(2, MOD - 2) << endl;
  cout << res;

  return 0;
}


