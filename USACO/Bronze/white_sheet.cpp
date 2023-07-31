#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Rectangle {
  ll x1, y1, x2, y2;
  ll getArea() {
    return (ll) (x2 - x1) * (y2 - y1);
  }
  Rectangle(ll _x1, ll _y1, ll _x2, ll _y2) {
    x1 = _x1;
    y1 = _y1;
    x2 = _x2;
    y2 = _y2;
  }
  Rectangle() {
  };
};

istream &operator >> (istream &in, Rectangle &r) {
  in >> r.x1 >> r.y1 >> r.x2 >> r.y2;
  return in;
}

ll llersectArea(const Rectangle &r1, const Rectangle &r2) {
  return max(min(r1.y2, r2.y2) - max(r1.y1, r2.y1), (ll)0) * max(min(r1.x2, r2.x2) - max(r1.x1, r2.x1), (ll)0);
}

Rectangle llersect(const Rectangle &r1, const Rectangle &r2) {
  if (llersectArea(r1, r2) <= 0) return Rectangle(-1, -1, -1, -1);
  Rectangle res;
  res.x1 = max(r1.x1, r2.x1);
  res.y1 = max(r1.y1, r2.y1);
  res.x2 = min(r1.x2, r2.x2);
  res.y2 = min(r1.y2, r2.y2);
  return res;
}

int main() {

//  freopen("whitesheet.inp", "r", stdin);

  Rectangle b[2], w;
  cin >> w >> b[0] >> b[1];

  ll remainArea = w.getArea();

  for (ll i = 0; i < 2; ++i) {
    remainArea -= llersectArea(w, b[i]);
  }

  remainArea += llersectArea(llersect(b[0], b[1]), w);

  cout << (remainArea > 0? "YES": "NO");

  return 0;
}
