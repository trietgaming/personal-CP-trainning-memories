#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "revegetate";
const int MAXN = 100001;

struct Edge {
  int to;
  bool fake;
  Edge() {}
  Edge(int _to, bool _fake) {
    to = _to;
    fake = _fake;
  }
};

vector<Edge> edges[MAXN];
bool cant_place = false;
bool visited[MAXN], colored[MAXN];

void dfs(int node, bool color = true) {
  visited[node] = true;
  colored[node] = color;
  for (Edge adj: edges[node]) {
    if (visited[adj.to]) {
      if (colored[adj.to] == color && !adj.fake)
        cant_place = true;
      continue;
    }
    if (adj.fake) dfs(adj.to, color);
    else dfs(adj.to, !color);
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
  for (int i = 0; i < m; ++i) {
    char type;
    int a, b;
    cin >> type >> a >> b;
    bool is_fake = type == 'S';

    edges[a].push_back(Edge(b, is_fake));
    edges[b].push_back(Edge(a, is_fake));
  }

  string res = "1";

  for (int i = 1; i <= n; ++i) {
    if (visited[i]) continue;
    dfs(i, true);
    res += "0";
  }

  if (cant_place) cout << "0";
  else cout << res;

  return 0;
}


