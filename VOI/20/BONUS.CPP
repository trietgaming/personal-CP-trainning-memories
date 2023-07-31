#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "BONUS";
const int INF = 1e9 + 7;
const int MAXN = 300 + 5;

ll arr[MAXN];
ll dp[MAXN][MAXN][MAXN >> 1 | 1];

void maximize(ll &target, ll cmp) {
  target = max(target, cmp);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".inp").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  ll n, K;
  cin >> n >> K;

  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }

  ll res = 0;

  for (int l = 2; l <= n; ++l) {
    for (int i = 1; i <= n; ++i) {
      int j = i + l - 1;
      if (j > n) break;
      for (int k = 1; k <= min(K, (ll)l/2); ++k) {
        dp[i][j][k] = max({dp[i][j-1][k],
                           dp[i + 1][j][k],
                           dp[i + 2][j][k-1] + abs(arr[i] - arr[i + 1]),
                           dp[i][j - 2][k-1] + abs(arr[j] - arr[j-1]),
                           dp[i + 1][j - 1][k-1] + abs(arr[i] - arr[j])});
      }
      maximize(res, dp[i][j][K]);
    }
  }

  cout << res;

  return 0;
}
