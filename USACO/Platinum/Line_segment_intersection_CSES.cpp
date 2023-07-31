#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "";
const int INF = 1e9 + 7;
//const int MAXN =;

struct Point {
  using Vector2 = Point;
  ll x, y;
  Point(ll _x, ll _y): x(_x), y(_y) {
  }
  ll cross_product(Vector2 v) {
    return x * v.y - y * v.x;
  }
  ll cross_product(Point a, Point b) {
    return Vector2(a.x - x, a.y - y).cross_product(Vector2(b.x - x, b.y - y));
  }
  bool between(Point a, Point b) {
    return ((x <= b.x && x >= a.x) || (x >= b.x && x<= a.x)) && ((y>=a.y && y<=b.y) || (y>=b.y && y <=a.y));
  }

};

int sign(ll a) {
  if (!a) return 0;
  if (a<0) return -1;
  return 1;
}

using Vector2 = Point;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int T;
  cin >> T;
  while (T--) {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1>> y1>> x2>> y2>> x3>> y3>> x4>> y4;
    Point p1(x1, y1), p2(x2, y2), p3(x3, y3), p4(x4, y4);
    ll cr1 = p1.cross_product(p2, p3);
    ll cr2 = p1.cross_product(p2, p4);
    ll cr3 = p3.cross_product(p4, p1);
    ll cr4 = p3.cross_product(p4, p2);
    if (!cr1 && !cr2 && !cr3 && !cr4) {
      if (p1.between(p3, p4) || p2.between(p3, p4) || p3.between(p1, p2)) cout << "YES";
      else cout << "NO";
    } else if (sign(cr1) != sign(cr2) && sign(cr3) != sign(cr4)) cout << "YES";
    else
      {
      cout << "NO";
    }
    cout << "\n";
  }

  return 0;
}
