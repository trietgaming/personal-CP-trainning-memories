#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "snakes";
const int MAXNK = 401, INF = 1e9+7;

// last[i][s]: min waste up to pos i if current size is s
// dp[k][i]: min waste up to pos i at kth change
int dp[MAXNK][MAXNK], last[MAXNK][MAXNK];
int snakes[MAXNK];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  for (int i = 0; i < MAXNK; ++i) {
    for (int j = 0; j < MAXNK; ++j) {
      dp[i][j] = INF;
      last[i][j] = INF;
    }
  }

  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; ++i) {
    cin >> snakes[i];
  }

  for (int i = 0; i <= MAXNK; ++i) {
    // pos 0, i size
    last[0][i] = 0;
  }

  for (int s = 1; s <= n; ++s) {
    for (int j = 1; j <= n; ++j) {
      if (snakes[s] < snakes[j]) continue;
      last[j][s] = last[j-1][s] + abs(snakes[j] - snakes[s]);
      dp[0][j] = min(dp[0][j], last[j][s]);
    }
  }

   for (int change = 1; change <= k; ++change) {
     for (int s_ind = 1; s_ind <= n; ++s_ind) {
        if (snakes[s_ind] < snakes[change + 1]) continue;
        last[change + 1][s_ind] = dp[change-1][change] + abs(snakes[s_ind] - snakes[change + 1]);
        dp[change][change + 1] = min(dp[change][change + 1], last[change + 1][s_ind]);
     }
    for (int pos = change + 2; pos <= n; ++pos) {
      for (int s_ind = 1; s_ind <= n; ++s_ind) {
        if (snakes[s_ind] < snakes[pos]) continue;
        last[pos][s_ind] = min(last[pos - 1][s_ind], dp[change-1][pos-1]) + abs(snakes[s_ind] - snakes[pos]);
        dp[change][pos] = min(dp[change][pos], last[pos][s_ind]);
      }
    }
  }

//  for (int change = 0; change <= k; ++change) {
//    for (int s_ind = 1; s_ind <= n; ++s_ind) {
//      cout << snakes[s_ind] << "-> ";
//      for (int pos = 1; pos <= n; ++pos) {
//        cout << dp[change][pos][s_ind] << " ";
//      }
//      cout << endl;
//    }
//    cout << endl;
//  }

  int res = INT_MAX;
  for (int change = 0; change <= k; ++change) {
    res = min(res, dp[change][n]);
  }

  cout << res;

  return 0;
}


