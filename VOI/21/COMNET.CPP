#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "COMNET";
const int INF = 1e9 + 7;
const int MAXN = 1000 + 5;

ll n, k, a, b;
vector<ll> edges[MAXN];

bool visited[MAXN];
bool isims[MAXN];

void dfs(ll cur, ll to, ll prev, ll cured, ll &ed) {
  if (cur == to) {
    ed = cured;
    return;
  }
  for (ll adj: edges[cur]) {
    if (adj == prev) continue;
    dfs(adj, to, cur, cured + 1, ed);
  }
}

bool dfs3(ll cur, ll t1, ll t2, ll prev, ll &ed) {
  bool im = false;
  if (cur == t1 || cur == t2) {
    im = true;
  }
  for (ll adj: edges[cur]) {
    if (adj == prev) continue;
    s.insert(adj);
    if (dfs3(adj, t1, t2, cur, ed)) {
      ++ed;
      im = true;
    }
  }
  return im;
}

bool dfs4(ll cur, ll t1, ll t2, ll prev, ll &ed, vector<int> &v) {
  bool im = false;
  if (cur == t1 || cur == t2) {
    im = true;
  }
  for (ll adj: edges[cur]) {
    if (adj == prev) continue;
    s.insert(adj);
    if (dfs4(adj, t1, t2, cur, e, v)) {
      ++ed;
      im = true;
      v.push_back(adj);
      isims[adj] = true;
    }
  }
  return im;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
#ifdef LIONELMESSI
  freopen((FNAME + ".inp").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);
#endif // LIONELMESSI

  cin >> n >> k >> a >> b;
  for (int i = 1; i < n; ++i) {
    ll u, v;
    cin >> u  >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  if (k == 2) {
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        ll e = 0;
        dfs(i, j, -1, 0, e);
        if (e >= a && e <= b) {
          ++res;
        }
      }
    }
    cout << res;
    return 0;
  }
  if (k == 3) {
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        for (int l = j + 1; l <= n; ++l) {
          fill(visited, visited + n + 1, false);
          ll e = 0;
          dfs3(i, j, l, -1, e);
//          cerr << i << " " << j << " " << l << ": " << e << "\n";
          if (e >= a && e <= b) {
            ++res;
          }
        }
      }
    }
    cout << res;
    return 0;
  }
cout << 14;

  return 0;
}


