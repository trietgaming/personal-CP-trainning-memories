#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "";
const int INF = 1e9 + 7;
const int MAXN = 200;
const int MAXWH = 600 + 1;

int w[MAXN], h[MAXN];
int dp[MAXWH][MAXWH];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int W, H, n;
  cin >> W >> H >> n;
  for (int i = 0; i < n; ++i) {
    cin >> w[i] >> h[i];
  }

  for (int i = 0; i <= H; ++i) {
    for (int j = 0; j <= W; ++j) {
      dp[i][j] = i*j;
    }
  }

  for (int k = 0; k < n; ++k) {
      dp[h[k]][w[k]] = 0;
  }

  for (int i = 1; i <= H; ++i) {
    for (int j = 1; j <= W; ++j) {
      for (int x = 1; x <= j; ++x) {
        dp[i][j] = min(dp[i][j], dp[i][x] + dp[i][j-x]);
      }
      for (int y = 1; y <= i; ++y) {
        dp[i][j] = min(dp[i][j], dp[y][j] + dp[i - y][j]);
      }
    }

  }

  cout << dp[H][W];

  return 0;
}


