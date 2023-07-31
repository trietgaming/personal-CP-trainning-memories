#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "coincom";
const int MAXN = 100, MAXX = 1e6+1, MOD = 1e9+7;

int dp[MAXX], coins[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, x, min_coin = 1e9;
  cin >> n >> x;

  for (int i = 0; i < n; ++i) {
    cin >> coins[i];
    dp[coins[i]] = 1;
    min_coin = min(min_coin, coins[i]);
  }

  for (int i = min_coin + 1; i <= x; ++i) {
    for (int c = 0; c < n; ++c) {
      if (coins[c] > i) continue;
      dp[i] = (dp[i] + dp[i - coins[c]]) % MOD;
    }
  }

  cout << dp[x];

  return 0;
}


