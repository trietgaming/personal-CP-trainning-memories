#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "treedistance";
const int INF = 1e9 + 7;
const int MAXN = 2*1e5 + 1;

vector<int> edges[MAXN];
int longest_down[MAXN], which_longest_down[MAXN], longest_up[MAXN], longest[MAXN];

void dfs_down(int node, int prev = -1) {
  for (int adj: edges[node]) {
    if (adj == prev) continue;
    dfs_down(adj, node);
    if (longest_down[adj] + 1 > longest_down[node]) {
      longest_down[node] = longest_down[adj] + 1;
      which_longest_down[node] = adj;
    }
  }
}

void dfs_up(int node, int prev = -1) {
  longest[node] = max(longest_down[node], longest_up[node]);
  int l = 0;
  for (int adj: edges[node]) {
    if (adj == prev) continue;
    if (adj != which_longest_down[node])
      l = max(l, longest_down[adj] + 1);
  }
  for (int adj: edges[node]) {
    if (adj == prev) continue;
    if (adj == which_longest_down[node])
      longest_up[adj] = max({longest_up[adj], longest_up[node] + 1, l + 1});
    else
      longest_up[adj] = max(longest_up[adj], longest[node] + 1);
    dfs_up(adj, node);
  }
}

void dfs(int node) {
  dfs_down(node);
  dfs_up(node);
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

  for (int i = 1; i <= n; ++i) {
    cout << longest[i] << " ";
  }

  return 0;
}


