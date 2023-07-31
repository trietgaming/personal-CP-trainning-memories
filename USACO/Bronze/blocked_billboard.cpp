#include <bits/stdc++.h>

using namespace std;

struct Rectangle {
  int lx, ly, ux, uy;
  int getArea() {
    int e1 = ux - lx, e2 = uy - ly;
    return e1 * e2;
  }
};

int main() {

  freopen("billboard.in", "r", stdin);
  freopen("billboard.out", "w", stdout);

  Rectangle b[2], tr;

  cin >> b[0].lx >> b[0].ly >> b[0].ux >> b[0].uy;
  cin >> b[1].lx >> b[1].ly >> b[1].ux >> b[1].uy;
  cin >> tr.lx >> tr.ly >> tr.ux >> tr.uy;
  int res = b[0].getArea() + b[1].getArea();
  for (int i = 0; i < 2; ++i) {
    res -= max(0, (min(b[i].uy, tr.uy) - max(b[i].ly, tr.ly))) * max(0, (min(b[i].ux, tr.ux) - max(b[i].lx, tr.lx)));
  }

  cout << res;

  return 0;
}
