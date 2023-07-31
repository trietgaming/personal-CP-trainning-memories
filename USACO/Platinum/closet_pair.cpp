#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "";
const int INF = 1e9 + 7;
const int MAXN = 1e5;
//const double EPS = 0.00000001;
//
//int cmpDB(double a, double b) {
//  if (a - b < EPS) return -1;
//  if (a - b > EPS) return 1;
//  return 0;
//}

struct Point {
  double x, y;
  Point(double _x = 0, double _y = 0):x(_x), y(_y) {
  };
  bool operator < (Point o) {
    if (x == o.x) return y < o.y;
    return x < o.x;
  }
};

ostream &operator << (ostream &o, Point &p) {
  o << p.x << " " << p.y;
  return o;
}

struct cmp {
  bool operator () (const Point &a, const Point &b) const {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
  }
};

int n;
Point points[MAXN];

double sq_dist(Point a, Point b) {
  double sqx = a.x - b.x, sqy = a.y - b.y;
  return sqx*sqx + sqy*sqy;
}

void process() {
  for (int i = 0; i < n; ++i) {
    cin >> points[i].x >> points[i].y;
  }
  sort(points, points + n);
  set<Point, cmp> processed;
  pair<Point, Point> res;
  double sd = 1e18;
  stack<set<Point, cmp>::iterator> removes;
  for (int i = 0; i < n; ++i) {
    Point &p = points[i];
    double d = sqrt(sd);
    auto lo = processed.upper_bound({-1e9, p.y - d});
    while (lo != processed.end() && lo->y < p.y + d) {
      if (p.x - lo->x >= d) removes.push(lo);
      else {
        if (sq_dist(p, *lo) < sd) {
          sd = sq_dist(p, *lo);
          d = sqrt(sd);
          res.first = p;
          res.second = *lo;
        };
      }
      ++lo;
    }
    while (!removes.empty()) {
      processed.erase(removes.top());
      removes.pop();
    }
    processed.insert(p);
  }
  cout << res.first << " " << res.second;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  cout.precision(2);
  cin >> n;
  while (n) {
    cout << fixed;
    process();
    cout << "\n";
    cin >> n;
  };

  return 0;
}


