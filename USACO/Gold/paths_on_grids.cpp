#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "";
const int MAXN = 1001;

char grid[MAXN][MAXN];
ll dp[MAXN][MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> grid[i][j];
    }
  }

  if (grid[1][1] != '*') dp[1][1] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (grid[i][j] == '*') continue;
      dp[i][j] += dp[i-1][j] + dp[i][j-1];
      dp[i][j] %= 1000000007;
    }
  }

  cout << dp[n][n];

  return 0;
}


