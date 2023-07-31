#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "";
const int MAXN = 2*1e5;

struct SegmentTree {
  vector<ll> tree;
  const int n;
  SegmentTree(vector<ll> &arr): tree(4*(arr.size()) + 1), n(arr.size()) {
    build(arr, 1, 1, n);
  };
  void build(vector<ll> &arr, int id, int l, int r) {
    if (l == r) {
      tree[id] = arr[l - 1];
      return;
    }
    int mid = (l + r) / 2;
    build(arr, id << 1, l, mid);
    build(arr, id << 1 | 1, mid + 1, r);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
  }
  void update(int pos, int val, int id, int l, int r) {
    if (l > pos || r < pos) return;
    if (l == r) {
      tree[id] = val;
      return;
    }
    int mid = (l + r) / 2;
    update(pos, val, id << 1, l, mid);
    update(pos, val, id << 1 | 1, mid + 1, r);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
  }
  ll query(int l, int r, int id, int i, int j) {
    if (i > r || j < l) return 0;
    if (i >= l && j <= r) return tree[id];
    int mid = (i + j) / 2;
    return query(l, r, id << 1, i, mid) + query(l, r, id << 1 | 1, mid + 1, j);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  vector<ll> arr;
  int n, Q;
  cin >> n >> Q;

  for (int i = 1; i <= n; ++i) {
    arr.push_back(0);
    cin >> arr.back();
  }

  SegmentTree st(arr);

  while (Q--) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 1) {
      st.update(a, b, 1, 1, n);
    } else {
      cout << st.query(a, b, 1, 1, n) << "\n";
    }
  }

  return 0;
}


