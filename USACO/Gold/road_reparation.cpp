#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using Edge = pair<ll, pii>;

const string FNAME = "repair";
const int INF = 1e9 + 7;
const int MAXN = 1e5 + 1;

struct DSU {
  vector<int> parent;
  DSU(int n): parent(n + 1, -1) {};
  int get_root(int node) {
    return parent[node] < 0? node: parent[node] = get_root(parent[node]);
  }
  bool is_same_component(int u, int v) {
    return get_root(u) == get_root(v);
  }
  int size_of(int node) {
    return -parent[get_root(node)];
  }
  bool unite(int u, int v) {
    int s = get_root(u), b = get_root(v);
    if (s == b) return false;
    if (s < b) swap(s, b);
    parent[b] += parent[s];
    parent[s] = b;
    return true;
  }
};

bool visited[MAXN];
vector<Edge> edges;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, m;
  cin >> n >> m;

  DSU dsu(n);

  for (int i = 0; i < m; ++i) {
    ll a, b, c;
    cin >> a >> b >> c;

    edges.push_back({c, {a, b}});
  }

  sort(edges.begin(), edges.end());

  ll res = 0;
  for (Edge e: edges) {
    int u = e.second.first, v = e.second.second;
    if (dsu.is_same_component(u, v)) continue;
    dsu.unite(u, v);
    res += e.first;
  }

  if (dsu.size_of(1) != n) cout << "IMPOSSIBLE";
  else cout << res;

  return 0;
}


