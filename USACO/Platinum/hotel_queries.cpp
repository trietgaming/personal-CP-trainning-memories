#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "";
const int INF = 1e9 + 7;
const int MAXN = 2*1e5+1;

int hotels[MAXN];

struct SegmentTree {
  vector<int> st;
  int n;
  int f(int a, int b) {
    return max(a, b);
  }
  SegmentTree(int _n): st(4*_n), n(_n) {
    for (int i = 1; i <= n; ++i) {
      update(i, hotels[i]);
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
  void update(int pos, int val) {
    hotels[pos] = val;
    _update(1, 1, n, pos, val);
  }
  int query(int id, int l, int r, int val) {
    if (st[id] < val) return -1;
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (st[id << 1] >= val) return query(id << 1, l, mid, val);
    return query(id << 1 | 1, mid + 1, r, val);
  }
  int find_first_greater_or_equal(int x) {
    return query(1, 1, n, x);
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
  for (int i = 1; i <= n; ++i) {
    cin >> hotels[i];
  }
  SegmentTree st(n);
  for (int i = 0; i < m; ++i) {
    int g;
    cin >> g;
    int pos = st.find_first_greater_or_equal(g);
    if (pos == -1) cout << 0 << " ";
    else {
      cout << pos << " ";
      st.update(pos, hotels[pos] - g);
    }
  }

  return 0;
}


