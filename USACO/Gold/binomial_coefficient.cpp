#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "";
const int MAXN = 100000, MAXAB = 1000000, MOD = 1e9+7;
ll factorial_mod[MAXAB + 1];

ll binary_exponent(ll base, ll p) {
  if (p == 0) return 1;
  ll res = binary_exponent(base, p / 2);
  res = (res * res) % MOD;
  if (p & 1) res = (res * base) % MOD;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  factorial_mod[0] = 1;
  for (int i = 1; i <= MAXAB; ++i) {
    factorial_mod[i] = (factorial_mod[i - 1] * i) % MOD;
  }

  int n, a, b;
  cin >> n;

  while (n--) {
    cin >> a >> b;
    cout << (((factorial_mod[a] * binary_exponent(factorial_mod[b], MOD - 2)) % MOD) * binary_exponent(factorial_mod[a - b], MOD - 2)) % MOD;
    cout << "\n";
  }

  return 0;
}


