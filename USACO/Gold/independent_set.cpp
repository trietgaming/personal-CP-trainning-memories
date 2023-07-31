#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "";
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 1;

ll dpb[MAXN], dpw[MAXN];
vector<int> edges[MAXN];

void dfs(int node, int prev = -1) {
  vector<int> child;
  for (int adj: edges[node]) {
    if (adj == prev) continue;
    child.push_back(adj);
    dfs(adj, node);
  }
  if (child.empty()) {
    dpb[node] = 1;
    dpw[node] = 1;
  }
  else for (int c: child) {
    dpb[node] = (dpb[node] * dpw[c]) % MOD;
    dpw[node] = (dpw[node] * ((dpb[c] + dpw[c]) % MOD)) % MOD;
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

  fill(dpw, dpw + 1 + n, 1);
  fill(dpb, dpb + 1 + n, 1);
  dfs(1);
//  for (int i = 1; i <= n; ++i) cout << i << " : " << dpb[i] << "\n";
//  cout << endl;
//
//  for (int i = 1; i <= n; ++i) cout << i << " : " << dpw[i] << "\n";

  cout << (dpb[1] + dpw[1]) % MOD;

  return 0;
}


