#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "cowjump";
const int INF = 1e9 + 7;
const int MAXN = 1e5 + 1;

struct Point {
  ll x, y;
  int sid;
  Point (ll a = -1, ll b = -1, int id = 0): x(a), y(b), sid(id) {
  }
  bool operator < (Point &o) {
    if (x == o.x) return y < o.y;
    return x < o.x;
  }
  ll cross_product(Point &a, Point &b) {
    ll x1 = a.x - x, y1 = a.y - y;
    ll x2 = b.x - x, y2 = b.y - y;
    return x1*y2 - x2*y1;
  }
};
struct Segment {
  Point l, r;
  Segment(Point a = Point(), Point b = Point()) {
    if (b < a) swap(a, b);
    l = a;
    r = b;
  }
  bool is_intersect_with(Segment &o) {
    return l.cross_product(r, o.l) * l.cross_product(r, o.r) < 0 && o.l.cross_product(o.r, l) * o.l.cross_product(o.r, r) < 0;
  }
};
struct Event {
  Point p;
  bool is_right;
  Event(Point a, bool r): p(a), is_right(r) {}
  bool operator < (Event &o) const {
    if (p.x == o.p.x) return p.y < o.p.y;
    return p.x < o.p.x;
  }
};

struct cmp {
  bool operator() (const Point &a, const Point &b) const {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
  }
};

vector<Segment> lines;
vector<Event> sweep;
set<Point, cmp> active;

bool found = false;
Segment res1, res2;

void check_inter_and_update(Point a, Point b) {
  Segment s1 = lines[a.sid], s2 = lines[b.sid];
  if (s1.is_intersect_with(s2)) {
    found = true;
    res1 = s1;
    res2 = s2;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;;
    lines.push_back(Segment({x1, y1, i}, {x2, y2, i}));
    sweep.push_back({lines[i].l, false});
    sweep.push_back({lines[i].r, true});
  }

  sort(sweep.begin(), sweep.end());

  for (Event e: sweep) {
    if (found) break;
    if (e.is_right) {
      set<Point, cmp>::iterator it = active.lower_bound(e.p);
      if (it != active.begin() && it != active.end()) check_inter_and_update(*prev(it), *next(it));
      active.erase(lines[e.p.sid].l);
    } else {
      set<Point, cmp>::iterator it = active.insert(e.p).first;
      if (it != active.begin()) check_inter_and_update(*it, *prev(it));
      if (it != active.end()) check_inter_and_update(*it, *next(it));
    }
  }

  if (res2.l.sid < res1.l.sid) swap(res1, res2);
  int inters= 0;
  for (int i = 0; i < n; ++i) {
    if (i == res2.l.sid) continue;
    if (res2.is_intersect_with(lines[i])) ++inters;
  }

  if (inters > 1) cout << res2.l.sid + 1;
  else cout << res1.l.sid + 1;

  return 0;
}


