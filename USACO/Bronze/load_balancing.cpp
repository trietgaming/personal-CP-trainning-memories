#include <bits/stdc++.h>

using namespace std;

struct Point {
  int x, y;
  Point() { x = 0; y = 0;};
  Point(int _x, int _y) {
    x = _x;
    y = _y;
  }
};

Point points[100];

int main() {

  freopen("balancing.in", "r", stdin);
  freopen("balancing.out", "w", stdout);

  int n, B;
  cin >> n >> B;

  for (int i = 0; i < n; ++i) {
    cin >> points[i].x >> points[i].y;
  }
  int res = INT_MAX;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      Point line(points[i].x - 1, points[j].y - 1);
      int M = 0;
      vector<int> halves(4, 0);
      for (int p = 0; p < n; ++p) {
        Point point = points[p];
        bool lu = point.x < line.x && point.y > line.y;
        bool ld = point.x < line.x && point.y < line.y;
        bool ru = point.x > line.x && point.y > line.y;
        bool rd = point.x > line.x && point.y < line.y;
        if (lu) halves[0]++;
        else if (ld) halves[1]++;
        else if (ru) halves[2]++;
        else halves[3]++;
      }
      for (int ma: halves) M = max(M, ma);
      res = min(res, M);
    }
  }

  cout << res;

  return 0;
}
