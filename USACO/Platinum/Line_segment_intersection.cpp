
#include <bits/stdc++.h>

using namespace std;
using ll = long double;
using lb = ll;
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
    return ((x >= a.x &&x <= b.x)||(x >= b.x &&x <= a.x)) && ((y>= b.y && y <= a.y)||(y>= a.y && y <= b.y));
  }
  void print() {
    cout << x << " " << y;
  }
};

 bool operator < (Point a, Point b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

bool operator == (Point a, Point b) {
  return a.x == b.x && a.y == b.y;
}

int sign(ll a) {
  if (a == 0) return 0;
  if (a < 0) return -1;
  return 1;
}

Point getIntersection(Point p1, Point p2, Point p3, Point p4)  {
  lb P = p2.y - p1.y, Q = p1.x - p2.x;
  lb M = p4.y - p3.y, N = p3.x - p4.x;
  lb C1 = (-P)*p1.x - Q*p1.y;
  lb C2 = (-M)*p3.x - N*p3.y;
  lb resY = (M*C1 - P*C2) / (P*N - M*Q);
  if (P == 0) return {0, resY};
  lb resX = (-C1 - Q*resY) / P;
  return Point(resX, resY);
}

void print_line(Point s, Point e) {
    if (e < s) swap(s, e);
    s.print();
    cout << " ";
    e.print();
}

using Vector2 = Point;

void process() {
  ll x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1>> y1>> x2>> y2>> x3>> y3>> x4>> y4;
  Point p1(x1, y1), p2(x2, y2), p3(x3, y3), p4(x4, y4);
  ll cr1 = p1.cross_product(p2, p3);
  ll cr2 = p1.cross_product(p2, p4);
  ll cr3 = p3.cross_product(p4, p1);
  ll cr4 = p3.cross_product(p4, p2);

  if (cr1 == 0 && cr2 == 0 && cr3 == 0 && cr4 == 0) {
    if (p1 == p2 && p1.between(p3, p4)) return p1.print();
    if (p3 == p4 && p3.between(p1, p2)) return p3.print();
    if (p2 < p1) swap(p1, p2);
    if (p4 < p3) swap(p3, p4);
    if (p1.between(p3, p4) && p2.between(p3, p4)) return print_line(p1, p2);
    if (p3.between(p1, p2) && p4.between(p1, p2)) return print_line(p3, p4);
    if (p1.between(p3, p4)) return print_line(p1, p4);
    if (p2.between(p3, p4)) return print_line(p2, p4);
    if (p3.between(p1, p2)) return print_line(p3, p2);
    if (p4.between(p1, p2)) return print_line(p4, p2);
    cout << "none";
    return;
  } if (cr1 == 0 || cr2 == 0 || cr3 == 0 || cr4 == 0) {
    if (p1 == p3 || p1 == p4) return p1.print();
    if (p2 == p3 || p2 == p4) return p2.print();
    if (p3 == p1 || p3 == p2) return p3.print();
    if (p4 == p1 || p4 == p2) return p4.print();
  }
  if (sign(cr1) != sign(cr2) && sign(cr3) != sign(cr4))
    return getIntersection(p1, p2, p3, p4).print();
  cout << "none";
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int T;
  cin >> T;
  cout.precision(2);
  while (T--) {
    cout << fixed;
    process();
    cout << "\n";
  }

  return 0;
}

