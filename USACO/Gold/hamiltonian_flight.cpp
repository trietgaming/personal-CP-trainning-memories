#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "hamilton";
const int MAXN = 20 + 1, MOD = 1e9+7;

vector<int> back_edges[MAXN];
int dp[1 << MAXN][MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    back_edges[b].push_back(a);
  }


  dp[1][1] = 1;

  for (int s = 2; s < (1 << n); ++s) {
    if (s & (1 << (n - 1)) && s != (1 << n) - 1) continue;
    for (int i = 1; i <= n; ++i) {
      if ((1 << (i - 1)) & s) {
        int subset = s^(1 << (i - 1));
        for (int b: back_edges[i]) {
          dp[s][i] = (dp[subset][b] + dp[s][i]) % MOD;
        }
      }
    }
  }

  cout << dp[(1 << n) - 1][n];

  return 0;
}


