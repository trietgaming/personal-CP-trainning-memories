#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

const string FNAME = "floyd";
const int MAXN = 501;
const ll INF = 500*500*1e10 + 1;

ll dp[MAXN][MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, m, Q;
  cin >> n >> m >> Q;

  for (int i = 0; i <= n; ++i) {
    fill(dp[i], dp[i] + n + 1, INF);
    dp[i][i] = 0;
  }

  for (int i = 0; i < m; ++i) {
    int a, b;
    ll w;
    cin >> a >> b >> w;
    dp[a][b] = min(dp[a][b], w);
    dp[b][a] = min(dp[b][a], w);
  }

  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (dp[i][k] < INF && dp[k][j] < INF) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
      }
    }
  }

  while (Q--) {
    int a, b;
    cin >> a >> b;
    if (dp[a][b] == INF) cout << -1 << "\n";
    else cout << dp[a][b] << "\n";
  }

  return 0;
}


