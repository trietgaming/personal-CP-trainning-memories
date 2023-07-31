#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "";
//const int MAXN =;

struct DSU {
  vector<int> parent;
  int largest, component_num;
  DSU(int n): parent(n + 1, -1), largest(1), component_num(n) {}
  int get_root(int node) {
    return parent[node] < 0? node: parent[node] = get_root(parent[node]);
  }
  void unite(int u, int v) {
    int s = get_root(u), b = get_root(v);
    if (s == b) return;
    if (s < b) swap(s, b);
    --component_num;
    parent[b] += parent[s];
    parent[s] = b;
    largest = max(largest, -parent[b]);
  }
};

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
    int a, b;
    cin >> a >> b;
    dsu.unite(a, b);
    cout << dsu.component_num << " " << dsu.largest << "\n";
  }

  return 0;
}


