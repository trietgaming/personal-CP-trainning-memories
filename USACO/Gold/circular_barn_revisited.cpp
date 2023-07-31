#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "cbarn2";
const ll INF = 1e18;
const int MAXN = 100 + 1, MAXK = 7 + 1, MAXCOWINAROOM = 1e6 + 1;

ll dp[MAXN][MAXN][MAXK], dist[MAXN][MAXN];
ll rooms[MAXN];
ll n, k;

ll move_room(ll pos, ll distance) {
  return (pos + distance + n) % n;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  for (int i = 0; i < MAXN; ++i) {
    for (int j = 0; j < MAXN; ++j) {
      fill(dp[i][j], dp[i][j] + MAXK, INF);
    }
  }

  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> rooms[i];
  }

  for (int i = 0; i < n; ++i) {
    dist[i][i] = 0;
    for (int m = 1; m < n; ++m) {
      int dest = move_room(i, m);
      dist[i][dest] = dist[i][move_room(i, m-1)] + rooms[dest] * m;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = move_room(i, 1); j != i; j = move_room(j, 1)) {
      dp[i][j][1] = dist[i][j];
    }
  }

  for (int t = 2; t <= k; ++t) {
    for (int i = 0; i < n; ++i) {
      for (int j = move_room(i, 1); j != i; j = move_room(j, 1)) {
        dp[i][j][t] = dp[i][j][t-1];
        for (int door = move_room(i, 1); door != move_room(j, 1); door = move_room(door, 1)) {
            dp[i][j][t] = min(dp[i][j][t], dp[i][door - 1][t - 1] + dist[door][j]);
        }
      }
    }
  }

  ll res = INF;

  for (int i = 0; i < n; ++i) res = min(res, dp[i][move_room(i, -1)][k]);

  cout << res;

  return 0;
}


