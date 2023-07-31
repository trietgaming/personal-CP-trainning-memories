#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "hps";

const int MAXN = 1e5 + 1, MAXK = 20 + 1, MAXGESTURES = 3;

int gesture_to_int[256], dp[MAXN][MAXK][MAXGESTURES], enemy_gestures[MAXN];
int n, k;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n >> k;

  gesture_to_int['P'] = 0;
  gesture_to_int['H'] = 1;
  gesture_to_int['S'] = 2;

  char c;
  for (int i = 1; i <= n; ++i) {
    cin >> c;
    enemy_gestures[i] = gesture_to_int[c];
  }

  for (int a = 1; a <= k + 1; ++a) {
    for (int g = 0; g < 3; ++g) {
      for (int i = 1; i <= n; ++i) {
        int max_prev = 0;
        for (int another = 0; another < 3; ++another) {
          if (another == g) continue;
          max_prev = max(max_prev, dp[i-1][a-1][another]);
        }
        dp[i][a][g] = max(dp[i-1][a][g], max_prev) + (enemy_gestures[i] == g);
      }
    }
  }

  int res = 0;
  for (int i = 1; i <= k + 1; ++i) {
    for (int g = 0; g < 3; ++g) {
      res = max(res, dp[n][i][g]);
    }
  }

  cout << res;

  return 0;
}
