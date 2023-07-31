#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "time";
const int MAXN = 1000 + 1, MAXM = 2000+1, MAXDAYS = 1001;

ll money[MAXN], dp[MAXDAYS][MAXN];
vector<int> edges[MAXN], back_edges[MAXN];
bool visited[MAXN];
int n, m, C;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n >> m >> C;

  for (int i = 1; i <= n; ++i) {
    cin >> money[i];
  }

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    back_edges[b].push_back(a);
  }

  fill(dp[1], dp[1] + MAXN, -1000000007);
  for (int adj: edges[1]) {
    dp[1][adj] = money[adj] - C;
  }
  for (int i = 2; i < MAXDAYS; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int adj: back_edges[j]) {
        dp[i][j] = max(dp[i][j], dp[i - 1][adj] + money[j] - C*(2*(i-1) + 1));
      }
    }
  }

  ll res = 0;
  for (int i = 0; i < MAXDAYS; ++i) {
    res = max(res, dp[i][1]);
  }

  cout << res;

  return 0;
}


