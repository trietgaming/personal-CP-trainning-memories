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

  freopen("square.in", "r", stdin);
  freopen("square.out", "w", stdout);

  Rectangle r1, r2;

  cin >> r1 >> r2;

  // Find the longest edge => cover all the recs
  cout << pow(max(
                  max(r1.x2, r2.x2) - min(r1.x1, r2.x1),
                  max(r1.y2, r2.y2) - min(r1.y1, r2.y1)
              ), 2);

  return 0;
}
