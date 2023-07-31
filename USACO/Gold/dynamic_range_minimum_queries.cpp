#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "";
const int INF = 1e9 + 7;

struct SegmentTree {
  vector<int> st;
  int n;
  int f(int a, int b) {
    return min(a, b);
  }
  SegmentTree(int n): st(4*n + 1), n(n) {}
  void _update(int id, int l, int r, int pos, int val) {
    if (l > pos || r < pos) return;
    if (l == r) {
      st[id] = val;
      return;
    }
    int mid = (l + r) >> 1;
    _update(id << 1, l, mid, pos, val);
    _update(id << 1 | 1, mid + 1, r, pos, val);
    st[id] = f(st[id << 1], st[id << 1 | 1]);
  }
  int _query(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return INF;
    if (l >= ql && r <= qr) return st[id];
    int mid = (l + r) >> 1;
    return f(_query(id << 1, l, mid, ql, qr), _query(id << 1 | 1, mid + 1, r, ql, qr));
  }
  void update(int pos, int val) {
    _update(1, 1, n, pos, val);
  }
  int query(int l, int r) {
    return _query(1, 1, n, l, r);
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

  SegmentTree st(n);

  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    st.update(i, a);
  }

  while (Q--) {
    int type, a, b;
    cin >> type >> a >> b;
    if (type == 1) {
      st.update(a, b);
    } else {
      cout << st.query(a, b) << "\n";
    }
  }

  return 0;
}
