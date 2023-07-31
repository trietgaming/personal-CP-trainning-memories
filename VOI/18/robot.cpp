#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1001;
const string FNAME = "ROBOT";
const int MAXLENGTH = 3*1e5;
const ll INF = 1e18;

char grid[MAXN][MAXN];
struct Point {
  ll x, y;
  Point (ll a = 0, ll b = 0): x(a), y(b) {};
  Point operator + (Point a) {
    return Point(x + a.x, y +  a.y);
  }
  friend Point operator * (Point p, ll m) {
    return Point(p.x *m, p.y*m);
  }
};

// 0 len, 1 trai, 2 xuong, 3 phai
Point dir[4];

Point pos_after[MAXLENGTH];
ll dir_at[MAXLENGTH];
ll visited[MAXN][MAXN];

void change_dir(int &cdir) {
  cdir = (cdir + 1) % 4;
}
ll n, x, y, S;

void rotate_p(Point current, int &cur_dir) {
  while (true) {
    Point next = current + dir[cur_dir];
    if (next.x >= 1 && next.y >= 1 && next.x <= n && next.y <= n) {
      if (grid[next.y][next.x] == '#') {
        change_dir(cur_dir);
        continue;
      }
      return;
    }
    return;
  }
}

pair<ll, ll> loop_range;

int main() {
  dir[0] = Point(0, -1);
  dir[1] = Point(-1, 0);
  dir[2] = Point(0, 1);
  dir[3] = Point(1, 0);
  loop_range = pair<ll, ll>(INF, INF);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

//  freopen((FNAME+".inp").c_str(), "r", stdin);
//  freopen((FNAME+".out").c_str(), "w", stdout);

  cin >> n >> x >> y >> S;
  for (int i = 0; i <= n; ++i)
    fill(visited[i], visited[i] + n + 1, -1);

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> grid[i][j];
    }
  }

  pos_after[0] = Point(x, y);
  Point current = Point(x,y);
  if (current.x >= 1 && current.y >= 1 && current.x <= n && current.y <= n)
    visited[current.y][current.x] = 0;
  int cur_dir = 0;
  rotate_p(current, cur_dir);
  dir_at[0] = cur_dir;
  for (int i = 1; i < MAXLENGTH; ++i) {
    current = current + dir[cur_dir];
    rotate_p(current, cur_dir);
    dir_at[i] = cur_dir;
    if (current.x >= 1 && current.y >= 1 && current.x <= n && current.y <= n) {
      if (visited[current.y][current.x] != -1 && dir_at[visited[current.y][current.x]] == cur_dir) {
        loop_range.first = visited[current.y][current.x];
        loop_range.second = i - 1;
        break;
      } else {
        visited[current.y][current.x] = i;
      }
    }
    pos_after[i] = current;
//    cerr << i << "->" << dir_at[i] <<"\n";
  }

  cerr << "loop:" << loop_range.first << " " << loop_range.second << endl;
  if (loop_range.first != INF) {
    if (S < loop_range.first) {
        cerr << "rere";
      cout << pos_after[S].x << " " << pos_after[S].y;
    }
    else {
       cerr << "rereasd ";
      ll l = loop_range.second - loop_range.first + 1;

      S -= loop_range.first;
      loop_range.second -= loop_range.first;
//        cerr <<
      cout << pos_after[(S % l) + loop_range.first].x << " " << pos_after[(S % l) + loop_range.first].y;

    }
  } else {
    if (S < MAXLENGTH)
      cout << pos_after[S].x << " " << pos_after[S].y;
    else {
      Point p = pos_after[MAXLENGTH-1] + (dir[dir_at[MAXLENGTH-1]] * (S - MAXLENGTH + 1));
      cout << p.x << " " << p.y;
    }
  }

  return 0;
}
