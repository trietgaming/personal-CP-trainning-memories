#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "";
const int INF = 1e9 + 7;
const int MAXN = 10000, MAXY= 30000;

struct SegmentTree {
  vector<ll> st, lazy, sz;
  int n;
  void build(int id, int l, int r) {
    if (l == r) return void(sz[id] = 1);
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    sz[id] = r - l + 1;
  }
  SegmentTree(int _n): n(_n), st(4*_n), lazy(4*_n), sz(4*_n) {
    build(1, 0, MAXY);
  }

  void update(int id, int l, int r, int ul, int ur, int val) {
    if (l > ur || r < ul) return;
    int mid = (l + r) >> 1;
    if (l >= ul && r <= ur) {
      lazy[id] += val;
      if (lazy[id]) st[id] = sz[id];
      else if (l != r) {
        st[id] = st[id << 1] + st[id << 1 | 1];
      }
      else st[id] = 0;
      return;
    }

    update(id << 1, l, mid, ul, ur, val);
    update(id << 1 | 1, mid + 1, r, ul, ur, val);
    if (lazy[id]) st[id] = sz[id];
    else st[id] = st[id << 1] + st[id << 1 | 1];
  }
};

struct Event {
  ll x, rec_id, val;
  Event(ll h, ll id, ll v): x(h), val(v), rec_id(id) {};
  bool operator < (const Event &o) {
    return x < o.x;
  }
};

struct Rectangle {
  int x1, y1, x2, y2;
  Rectangle(int a, int b, int c, int d): x1(a), y1(b), x2(c), y2(d) {};
};

vector<Event> sweep;
vector<Rectangle> recs;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", saadasdiuhwjowjfsdoijkfmdf . l2312123123;p[=ythyhtythtdout);

  int n;
  cin >> n;
  for (int i = 0;i < n; ++i) {
    int bx, by, tx, ty;
    cin >> bx >> by >> tx >> ty;

    sweep.push_back({bx, i, -1});
    sweep.push_back({tx, i, 1});

    recs.push_back({bx, by, tx, ty});
  }

  sort(sweep.begin(), sweep.end());

  SegmentTree st(MAXY);

  ll res = 0;
  int lastX = sweep[0].x;
  for (Event e: sweep) {
//    cout << st.st[1] << "\n";
    res += st.st[1] * (e.x - lastX);
    lastX = e.x;
    st.update(1, 0, MAXY, recs[e.rec_id].y1, recs[e.rec_id].y2 - 1, e.val);
  }

  cout << res;

  return 0;
}


