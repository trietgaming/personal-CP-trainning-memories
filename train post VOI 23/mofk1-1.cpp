#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "";
const ll INF = 1e18 + 7;
const int MAXN = 1000 + 5;

ll dp[MAXN][MAXN], grid[MAXN][MAXN];

int n, m;

void maximize(ll &target, ll val) {
  target = max(target, val);
}

bool valid(ll s) {
  for (int i = 0; i <= n; ++i) {
    fill(dp[i], dp[i] + m + 1, -1);
  }
  dp[0][1] = s;
  dp[1][0] = s;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (dp[i - 1][j] > grid[i][j]) maximize(dp[i][j], dp[i-1][j] + grid[i][j]);
      if (dp[i][j - 1] > grid[i][j]) maximize(dp[i][j], dp[i][j - 1] + grid[i][j]);
    }
  }
  return dp[n][m] != -1;
}

ll solve(ll l, ll r) {
  if (l == r) {
    return l;
  }
  ll mid = l + (r-l) / 2;
  if (valid(mid)) return solve(l, mid);
  return solve(mid + 1, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> grid[i][j];
    }
  }

  cout << solve(grid[1][1] + 1, INF);

  return 0;
}


