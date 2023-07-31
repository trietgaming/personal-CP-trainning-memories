#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "";
const int MOD = 1e9+7;

ll bin_pow(ll a, ll b, ll modulo) {
  if (b == 0) return 1;
  ll half = bin_pow(a, b / 2, modulo);
  ll res = ((half % modulo) * (half % modulo)) % modulo;
  if (b & 1) res = (res * (a % modulo)) % modulo;
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
    int a, b, c;
    cin >> a >> b >> c;
    cout << bin_pow(a, bin_pow(b, c, MOD - 1), MOD) << "\n";
  }

  return 0;
}


