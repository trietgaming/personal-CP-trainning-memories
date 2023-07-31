#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "countcycle";
const int INF = 1e9 + 7;
const int MAXN = 2*1e5 + 1;

int succ[MAXN];
int dp[MAXN];
bool visited[MAXN], in_stack[MAXN];

void dfs(int node, int gone = 0) {
  visited[node] = true;
  in_stack[node] = true;
  int adj = succ[node];

  if (in_stack[adj]) {
    dp[adj] = gone;
    dp[node] = dp[adj];
  }
  if (dp[adj] != -1) {
    dp[node] = dp[adj] + 1;
  }
  else if (!visited[adj]) {
    dfs(adj, gone + 1);
    if (dp[adj] != -1)
      dp[node] = dp[adj];
  }
  in_stack[node] = false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  fill(dp, dp + MAXN, -1);

  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> succ[i];
  }

  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      dfs(i);
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << dp[i] << " ";
  }

  return 0;
}


