#include <bits/stdc++.h>

using namespace std;

struct Point {
  int x,y;
};

const int MAXN = 1000;

bool sortByX(const Point &p1, const Point &p2) {
  return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
}

bool sortByY(const Point &p1, const Point &p2) {
  return p1.y < p2.y || (p1.y == p2.y && p1.x < p2.x);
}

Point px[MAXN], py[MAXN], points[MAXN];

int main() {

  freopen("balancing.in", "r", stdin);
  freopen("balancing.ans", "w", stdout);

  int n; cin >> n;


  for (int i = 0; i < n; ++i) {
    cin >> points[i].x >> points[i].y;
    py[i].x = px[i].x = points[i].x;
    py[i].y = px[i].y = points[i].y;
  }

  sort(px, px + n, sortByX);
  sort(py, py + n, sortByY);

  int res = INT_MAX;

  for (int hi = 0; hi < n; ++hi) {
    for (int vi = 0; vi < n; ++vi) {
      int ve = px[vi].x + 1, ho = py[hi].y + 1;
      int ul = 0, ur= 0, dl = 0, dr = 0;
      for (int p = 0; p < n; ++p) {
        Point &point = points[p];
        bool l = point.x < ve, u = point.y > ho, r = point.x > ve, d = point.y < ho;
        if (u&&l) ++ul;
        else if (u&&r) ++ur;
        else if (d&&l) ++dl;
        else ++dr;
      }
      res = min(res, max({ul, ur, dl, dr}));
    }
  }

  cout << res;

  return 0;
}
