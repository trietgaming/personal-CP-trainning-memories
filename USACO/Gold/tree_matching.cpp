#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "treematch";
const int INF = 1e9 + 7;
const int MAXN = 2*1e5 + 1;

int dp1[MAXN], dp2[MAXN];
vector<int> edges[MAXN];

void dfs(int node, int prev = -1) {
  vector<int> childs;
  for (int adj: edges[node]) {
    if (adj == prev) continue;
    childs.push_back(adj);
    dfs(adj, node);
  }
  for (int c: childs) {
    dp2[node] += dp1[c];
  }
  for (int c: childs) {
    dp1[node] = max(dp1[node], dp2[c] + 1 + dp2[node] - dp1[c]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;

    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  dfs(1);

  cout << max(dp1[1], dp2[1]);

  return 0;
}


