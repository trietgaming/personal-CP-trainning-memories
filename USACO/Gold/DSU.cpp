#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "DSU";
const int MAXN = 2*1e5 + 1;

struct DSU {
  vector<int> parent;
  DSU (int n = MAXN): parent(n, -1) {}
  int get_root(int node) {
    return parent[node] < 0? node: parent[node] = get_root(parent[node]);
  };
  bool is_same_component(int u, int v) {
    return get_root(u) == get_root(v);
  }
  void connect(int u, int v) {
    int s = get_root(u), b = get_root(v);
    if (s != b) {
      if (parent[b] > parent[s]) swap(s, b);
      parent[b] += parent[s];
      parent[s] = b;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, Q;
  cin >> n >> Q;

  DSU graph(n);

  while (Q--) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t) {
      cout << graph.is_same_component(u, v) << "\n";
    } else {
      graph.connect(u, v);
    }
  }

  return 0;
}


