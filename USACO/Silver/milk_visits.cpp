#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "milkvisits";
const int MAXN = 100001;

vector<int> edges[MAXN];
int node_in_component[MAXN];
char breed[MAXN];
int com_id = 1;

void dfs(int node, int prev = -1, int cur_id = com_id) {
  node_in_component[node] = cur_id;
  int o = cur_id;
  for (int adj: edges[node]) {
    if (adj == prev) continue;
    int com = breed[node] == breed[adj]? o: ++com_id;
    dfs(adj, node, com);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    cin >> breed[i];
  }

  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  dfs(1);

  for (int i = 0; i < m; ++i) {
    int a, b;
    char t;
    cin >> a >> b >> t;

    if (node_in_component[a] == node_in_component[b] && breed[a] != t) cout << 0;
    else cout << 1;
  }

  return 0;
}


