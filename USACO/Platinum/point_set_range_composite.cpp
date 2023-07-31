#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

const string FNAME = "noncombst";
const ll MAXN = 500001, MOD = 998244353;
const pii VOID_FUNC = {-1000000007, -1000000007};

pii arr[MAXN];

struct SegmentTree {
  vector<pii> st;
  int n;
  ll f(pii func, ll x) {
    return (((func.first * x) % MOD) + func.second) % MOD;
  }
  pii combine(pii o, pii i) {
    if (o == VOID_FUNC) return i;
    if (i == VOID_FUNC) return o;
    return {(o.first*i.first) % MOD, (((o.first * i.second) % MOD) + o.second) % MOD};
  }
  SegmentTree(int _n): st(4*_n, VOID_FUNC), n(_n) {
    for (int i = 1; i <= n; ++i) {
      update(i, arr[i]);
    }
  }

  void _update(int id, int l, int r, int pos, pii func) {
    if (l > pos || r < pos) return;
    if (l == r) return void(st[id] = func);
    int mid = (l + r) >> 1;
    _update(id << 1, l, mid, pos, func);
    _update(id << 1 | 1, mid + 1, r, pos, func);
    st[id] = combine(st[id << 1 | 1], st[id << 1]);
  }
  void update(int pos, pii func) {
    _update(1, 1, n, pos, func);
  }

  pii _query(int id, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return VOID_FUNC;
    if (l >= ql && r <= qr) return st[id];
    int mid = (l + r) >> 1;
    return combine(_query(id << 1 | 1, mid + 1, r, ql, qr), _query(id << 1, l, mid, ql, qr));
  }
  ll query(int l, int r, ll x) {
    pii func = _query(1, 1, n, l, r);
//    cout << func.first << "x + " << func.second << endl;
    return f(func, x) % MOD;
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
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i].first >> arr[i].second;
  }

  SegmentTree st(n);

//  cout << st.query(1, 1, 0) << "\n\n";

  while (Q--) {
    ll type, a, b, c;
    cin >> type >> a >> b >> c;
    if (type) {
      cout << st.query(a + 1, b, c) << "\n";
    } else {
      st.update(a + 1, pii(b, c));
    }
  }

  return 0;
}


