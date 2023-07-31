#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 100001;

struct Point {
  ll x, y;
  Point() {}
  Point (ll _x, ll _y) {
    x = _x;
    y = _y;
  }
};

Point operator + (const Point &a, const Point &b) {
  return Point(a.x + b.x, a.y + b.y);
}

Point operator * (const Point &a, ll b) {
  return Point(a.x * b, a.y * b);
}

Point start, destination, dir[256], offsets[MAXN];
ll n;

ll manhattan_distance(Point a, Point b) {
  return abs(b.x - a.x) + abs(b.y - a.y);
}

Point get_position_after(ll day) {
  return start + offsets[n] * (day / n) + offsets[day % n];
}

bool can_move_to_dest_within(ll days) {
  return manhattan_distance(get_position_after(days), destination) <= days;
}

ll find_min_day_moving_to_dest(ll l, ll r) {
  if (l == r) {
    if (can_move_to_dest_within(l)) return l;
    return -1;
  }
  ll mid = (l + r) / 2;
  if (can_move_to_dest_within(mid)) return find_min_day_moving_to_dest(l, mid);
  return find_min_day_moving_to_dest(mid + 1, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  dir['U'] = Point(0, 1);
  dir['D'] = Point(0, -1);
  dir['L'] = Point(-1, 0);
  dir['R'] = Point(1, 0);
  offsets[0] = Point(0, 0);

  cin >> start.x >> start.y;
  cin >> destination.x >> destination.y;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    char c;
    cin >> c;
    Point mov = dir[c];
    offsets[i] = offsets[i-1] + mov;
  }

  cout << find_min_day_moving_to_dest(0, (ll) 2*1e18);

  return 0;
}


