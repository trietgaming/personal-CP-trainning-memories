#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e16;

struct RectangleXY {
  ll x1, y1, x2, y2;
};

struct Rectangle {
  ll w, h;
};

istream &operator >> (istream &in, RectangleXY &r) {
  in >> r.x1 >> r.y1 >> r.x2 >> r.y2;
  return in;
}

istream &operator >> (istream &in, Rectangle &r) {
  in >> r.w >> r.h;
  return in;
}


void process() {
  Rectangle room, second;
  RectangleXY first, moved;

  cin >> room >> first >> second;
  moved = first;

  ll res = INF;

  ll moveH = INF;
  if (second.w > first.x1 && room.w - first.x2 >= second.w - first.x1) {
    moveH = second.w - first.x1;
  };
  if (room.w - first.x2 < second.w && first.x1 >= second.w - (room.w - first.x2)) {
    moveH = min(moveH, second.w - (room.w - first.x2));
  }

  res = min(res, moveH);

  ll moveV = INF;

  if (second.h > first.y1 && room.h - first.y2 >= second.h - first.y1) {
    moveV = second.h - first.y1;
  };
  if (room.h - first.y2 < second.h && first.y1 >= second.h - (room.h - first.y2)) {
    moveV = min(moveV, second.h - (room.h - first.y2));
  }

  res = min(res, moveV);

  if (res == INF) res = -1;
  if ((first.x1 >= second.w || room.w - first.x2 >= second.w) || (first.y1 >= second.h || room.h - first.y2 >= second.h))
    res = 0;

  cout << res << "\n";
}

int main() {
//
//  freopen("twotable.in", "r", stdin);

  int t;
  cin >> t;

  while (t--) {
    process();
  }

  return 0;
}
