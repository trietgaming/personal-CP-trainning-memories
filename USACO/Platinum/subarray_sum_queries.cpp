#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "";
const int INF = 1e9 + 7;
const int MAXN = 2*1e5 + 1;

ll arr[MAXN];

struct data {
  ll pre, suf, sum, ans;
  data(ll p = 0, ll s = 0, ll su = 0, ll a = 0): pre(p), suf(s), sum(su), ans(a) {}
};
const data VOIDDATA;

struct SegmentTree {
  vector<data> st;
  int n;
  data combine(data l, data r) {
    return data(max(l.pre, l.sum + r.pre), // prefix
                max(r.suf, r.sum + l.suf), // suffix
                l.sum + r.sum,             // sum
                max({l.ans, r.ans, l.suf + r.pre}) //ans
                );
  }
  SegmentTree(int _n): n(_n), st(4*_n) {
    for (int i = 1; i <= n; ++i) {
      update(i, arr[i]);
    }
  };
  void _update(int id, int l, int r, int pos, ll val) {
    if (l > pos || r < pos) return;
    if (l == r) {
      st[id] = combine(VOIDDATA, data(val, val, val, val));
      return;
    }
    int mid = (l + r) >> 1;
    _update(id << 1, l, mid, pos, val);
    _update(id << 1 | 1, mid + 1, r, pos, val);
    st[id] = combine(st[id << 1], st[id << 1 | 1]);
  }
  void update(int pos, ll val) {
    _update(1, 1, n, pos, val);
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
    cin >> arr[i];
  }

  SegmentTree st(n);

  while (m--) {
    ll k, val;
    cin >> k >> val;

    st.update(k, val);
    cout << st.st[1].ans << "\n";
  }

  return 0;
}


