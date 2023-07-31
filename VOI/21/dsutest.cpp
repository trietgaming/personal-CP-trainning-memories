#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "";
const int INF = 1e9 + 7;
//const int MAXN =;

struct DSU {
  vector<int> par;
  DSU(int n): par(n + 1, -1) {};
  ll get(ll node) {
    return par[node] < 0? node: (par[node] = get(par[node]));
  }
  ll sz(ll node) {
    return -get(par[node]);
  }
  bool same_component(ll u, ll v) {
    return get(u) == get(v);
  }
  bool unite(ll a, ll b) {
    ll u = get(a), v = get(b);
    if (u == v) return false;
    if (par[u] < par[v]) swap(u, v);
    par[v] += par[u];
    par[u] = v;
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  ll n, Q;
  cin >> n >> Q;

  DSU dsu(n);
  while (Q--) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t) {
      cout << dsu.same_component(u, v) << "\n";
    } else {
      dsu.unite(u, v);
    }
  }

  return 0;
}


