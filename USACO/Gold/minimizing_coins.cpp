#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "";
const int MAXN = 100, MAXX = 1e6+1, INF = 1e9;

int coins[MAXN], dp[MAXX];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, x;
  cin >> n >> x;

  for (int i = 0; i < n; ++i) {
    cin >> coins[i];
  }

  dp[0] = 0;
  for (int i = 1; i <= x; ++i) {
    dp[i] = INF;
    for (int c = 0; c < n; ++c) {
      if (i - coins[c] >= 0)
        dp[i] = min(dp[i], 1 + dp[i - coins[c]]);
    }
  }

  if (dp[x] == INF) cout << -1;
  else cout << dp[x];

  return 0;
}


