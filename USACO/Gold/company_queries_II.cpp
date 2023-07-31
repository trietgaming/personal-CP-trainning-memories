#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "";
const int INF = 1e9 + 7;
const int MAXN = 2*1e5 + 1;

int heights[MAXN], trav_arr_pos[MAXN];
vector<int> edges[MAXN], euler(1);

struct TravSegmentTree {
  vector<int> st;
  int n;
  int f(int node1, int node2) {
    return heights[node1] < heights[node2]? node1: node2;
  }
  TravSegmentTree(int _n): st(8*_n + 1, 0), n(euler.size() - 1) {
    for (int i = 1; i <= n; ++i) {
      _update(1, 1, n, i, euler[i]);
    }
  }
  void _update(int id, int l, int r, int pos, int val) {
    if (l > pos || r < pos) return;
    if (l == r) return void(st[id] = val);
    int mid = (l + r) >> 1;
    _update(id << 1, l, mid, pos, val);
    _update(id << 1 | 1, mid + 1, r, pos, val);
    st[id] = f(st[id << 1], st[id << 1 | 1]);
  }
  int _query(int id, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) return 0;
    if (l >= ql && r <= qr) return st[id];
    int mid = (l + r) >> 1;
    return f(_query(id << 1, l, mid, ql, qr), _query(id << 1 | 1, mid + 1, r, ql, qr));
  }
  int query(int node1, int node2) {
    int a = trav_arr_pos[node1], b = trav_arr_pos[node2];
    if (a > b) swap(a, b);
    return _query(1, 1, n, a, b);
  }
};

void dfs(int node, int depth = 1) {
  heights[node] = depth;
  trav_arr_pos[node] = euler.size();
  euler.push_back(node);
  for (int child: edges[node]) {
    dfs(child, depth + 1);
    euler.push_back(node);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  heights[0] = INF;

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, q;
  cin >> n >> q;
  for (int i = 2; i <= n; ++i) {
    int boss;
    cin >> boss;
    edges[boss].push_back(i);
  }

  dfs(1);
  TravSegmentTree st(n);
  while (q--) {
    int a, b;
    cin >> a >> b;

    cout << st.query(a, b) << "\n";
  }

  return 0;
}


