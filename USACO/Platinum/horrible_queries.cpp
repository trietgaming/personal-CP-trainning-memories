#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "";
const int INF = 1e9 + 7;
//const int MAXN =;

struct SegmentTree {
  vector<ll> st, lazy, sz;
  int n;
  void build(int id, int l, int r) {
    sz[id] = r - l + 1;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
  }
  SegmentTree(int _n): st(4*_n), lazy(4*_n), sz(4*_n), n(_n) {
    build(1, 1, n);
  }
  void push(int id) {
    st[id] += sz[id] * lazy[id];
    lazy[id << 1] += lazy[id];
    lazy[id << 1 | 1] += lazy[id];
    lazy[id] = 0;
  }
  ll get(int id) {
    return st[id] + lazy[id] * sz[id];
  }
  void _update(int id, int l, int r, int ul, int ur, ll val) {
    if (l > ur || r < ul) return;
    if (l >= ul && r <= ur) {
      lazy[id] += val;
      return;
    }
    push(id);
    int mid = (l + r) >> 1;
    _update(id << 1, l, mid, ul, ur, val);
    _update(id << 1 | 1, mid + 1, r, ul, ur, val);
    st[id] = get(id << 1) + get(id << 1 | 1);
  }
  void update(int l, int r, ll val) {
    _update(1, 1, n, l, r, val);
  }

  ll _query(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;
    if (l >= ql && r <= qr) return get(id);
    int mid = (l + r) >> 1;
    push(id);
    return _query(id << 1, l, mid, ql, qr) + _query(id << 1 | 1, mid + 1, r, ql, qr);
  }
  ll query(int l, int r) {
    return _query(1, 1, n, l, r);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int T;
  cin >> T;
  while (T--) {
    int n, C;
    cin >> n >> C;
    SegmentTree st(n);
    while (C--) {
      int type;
      cin >> type;
      if (type) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l, r) << "\n";
      } else {
        int l, r, val;
        cin >> l >> r >> val;
        st.update(l, r, val);
      }
    }
  }

  return 0;
}

