#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

const string FNAME = "";
const ll INF = 1e9 + 7;
const ll MAXN = 1e5 + 1;

struct SegmentTree {
  vector<ll> st;
  SegmentTree(): st(4*2000001) {
  }
  void add(ll id, ll l, ll r, ll pos, ll val) {
    if (l > pos || r < pos) return;
    if (l == r) return void(st[id] += val);
    ll mid = (l + r) / 2;
    add(id << 1, l, mid, pos, val);
    add(id << 1 | 1, mid + 1, r, pos, val);
    st[id] = st[id << 1] + st[id << 1 | 1];
  }
  ll query(ll id, ll l, ll r, ll ql, ll qr) {
    if (l > qr || r < ql) return 0;
    if (l >= ql && r <= qr) return st[id];
    ll mid = (l + r) / 2;
    return query(id << 1, l, mid, ql, qr) + query(id << 1| 1, mid + 1, r, ql, qr);
  }
};

struct Event {
  ll type, x1, x2, y, e;
  Event(ll t, ll l, ll r, ll h, ll val): type(t), x1(l), x2(r), y(h), e(val) {
  }
  ll process(SegmentTree &st) {
    if (type) {
      st.add(1, 0, 2000000, x1, e);
      return 0;
    }
    return st.query(1, 0, 2000000, x1, x2);
  }
};

bool cmp(Event &a, Event &b) {
  if (a.y == b.y) {
    return a.type > b.type;
  }
  return a.y < b.y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  ll n;
  cin >> n;

  vector<Event> points;

  for (ll i = 0; i < n; ++i) {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1 += 1000000;
    x2 += 1000000;
    y1 += 1000000;
    y2 += 1000000;
    if (x1 == x2) {
      points.push_back({1, x1, x2, y1 + 1, 1});
      points.push_back({1, x1, x2, y2, -1});
    } else {
      points.push_back({0, x1 + 1, x2 - 1, y1, 0});
    }
  }

  sort(points.begin(), points.end(), cmp);

  ll res = 0;
  SegmentTree st;
  for (auto p: points) res += p.process(st);

  cout << res;

  return 0;
}


