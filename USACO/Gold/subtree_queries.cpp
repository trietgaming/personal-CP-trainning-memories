#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "subtree";
const int INF = 1e9 + 7;
const int MAXN = 2*1e5+1;

ll values[MAXN], trav[MAXN];
int trav_id = 1;
vector<int> edges[MAXN];
pii trav_range[MAXN];

struct TravSegmentTree {
  vector<ll> st;
  int n;
  TravSegmentTree(int n): st(4*n + 1), n(n) {
    for (int i = 1; i <= n; ++i) update(i, values[i]);
  }
  void _update(int id, int l, int r, int pos, int val) {
    if (l > pos || r < pos) return;
    if (l == r) {
      st[id] = val;
      return;
    }
    int mid = (l + r) >> 1;
    _update(id << 1, l, mid, pos, val);
    _update(id << 1 | 1, mid + 1, r, pos, val);
    st[id] = st[id << 1] + st[id << 1 | 1];
  }
  ll _query(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;
    if (l >= ql && r <= qr) return st[id];
    int mid = (l + r) >> 1;
    return _query(id << 1, l, mid, ql, qr) + _query(id << 1 | 1, mid + 1, r, ql, qr);
  }

  ll query(int node) {
    return _query(1, 1, n, trav_range[node].first, trav_range[node].second);
  }
  void update(int node, int val) {
    _update(1, 1, n, trav_range[node].first, val);
  }
};

bool visited[MAXN];
void dfs(int node) {
  visited[node] = true;
  trav_range[node].first = trav_id;
  trav[trav_id++] = values[node];
  for (int adj: edges[node]) {
    if (visited[adj]) continue;
    dfs(adj);
  }
  trav_range[node].second = trav_id - 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, Q;
  cin >> n >> Q;

  for (int i = 1; i <= n; ++i) {
    int val;
    cin >> val;
    values[i] = val;
  }

  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  dfs(1);
  TravSegmentTree st(n);

  while (Q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int node, x;
      cin >> node >> x;
      st.update(node, x);
    } else {
      int node;
      cin >> node;
      cout << st.query(node) << "\n";
    }
  }

  return 0;
}


