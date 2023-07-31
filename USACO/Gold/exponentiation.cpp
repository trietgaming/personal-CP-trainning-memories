#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "";
const int MOD = 1e9+7;

ll binary_pow(ll base, ll exp) {
  if (exp == 0) return 1;
  ll res = binary_pow(base, exp / 2) % MOD;
  res *= res % MOD;
  res %= MOD;
  if (exp & 1) {
    res *= base % MOD;
    res %= MOD;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  while (n--) {
    int a, b;
    cin >> a >> b;
    cout << binary_pow(a, b) << "\n";
  }

  return 0;
}


