#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "";
//const int MAXN =;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, m;
  cin >> n >> m;

  ll ans = 1, preans = 0;
  if (n == 1) cout << preans;
  else {
    cout << preans << " " << ans << " ";
    for (int i = 3; i <= n; ++i) {
      ll temp = ((((i-1)*ans) % m) +(((i-1)*preans) % m)) % m;
      preans = ans;
      ans = temp;
      cout << ans << " ";
    }
  }

  return 0;
}


