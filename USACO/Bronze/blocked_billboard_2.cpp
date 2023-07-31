#include <bits/stdc++.h>

using namespace std;

struct Rectangle {
  int x1, y1, x2, y2;
};

istream &operator >> (istream &c, Rectangle &r) {
  c >> r.x1 >> r.y1 >> r.x2 >> r.y2;
  return c;
}

int main() {

  freopen("billboard.in", "r", stdin);
  freopen("billboard.out", "w", stdout);

  //behind - front
  Rectangle b, f;

  cin >> b >> f;
  int res;

  int yEdge = b.y2 - b.y1, xEdge = b.x2 - b.x1;

  bool coveredHorizontal = b.y2 <= f.y2 && b.y1 >= f.y1 && ((b.x2 > f.x1 && b.x2 <= f.x2) || (b.x1 < f.x2 && b.x1 >= f.x1));
  bool coveredVertical = b.x2 <= f.x2 && b.x1 >= f.x1 && ((b.y2 > f.y1 && b.y2 <= f.y2) || (b.y1 < f.y2 && b.y1 >= f.y1));
  if (coveredHorizontal && coveredVertical) res = 0;
  else if (coveredHorizontal) {
    res = yEdge * max(0, f.x1 - b.x1) + yEdge * max(0, b.x2 - f.x2);
  } else if (coveredVertical) {
    res = xEdge * max(0, f.y1 - b.y1) + xEdge * max(0, b.y2 - f.y2);
  } else res = xEdge * yEdge;

  cout << res;

  return 0;
}
