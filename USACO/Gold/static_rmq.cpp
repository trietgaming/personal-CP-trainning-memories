#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "";
const int INF = 1e9 + 7;
const int MAXN = 5*1e5+1;

int arr[MAXN];

struct SegmentTree {
  vector<int> st;
  int n;
  SegmentTree(int _n): st(4*_n + 1, INF), n(_n) {
    for (int i = 1; i <= n; ++i) {
      _update(1, 1, n, i, arr[i]);
    }
  }
  void _update(int id, int l, int r, int pos, int val) {
    if (l > pos || r < pos) return;
    if (l == r) return void(st[id] = val);
    int mid = (l + r) >> 1;
    _update(id << 1, l, mid, pos, val);
    _update(id << 1 | 1, mid + 1, r, pos, val);
    st[id] = min(st[id << 1], st[id << 1 | 1]);
  }
  int _query(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return INF;
    if (l >= ql && r <= qr) return st[id];
    int mid = (l + r) >> 1;
    return min(_query(id << 1, l, mid, ql, qr), _query(id << 1 | 1, mid + 1, r, ql, qr));
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

  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }
  SegmentTree st(n);
  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << st.query(a + 1, b) << "\n";
  }

  return 0;
}


