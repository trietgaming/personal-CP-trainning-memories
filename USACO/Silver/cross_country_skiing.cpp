#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Cell {
  int row, col;
  Cell () {}
  Cell (int r, int c) {
    row = r;
    col = c;
  }
};

const string FNAME = "ccski";
const int MAXN = 500;

const int dir_r[4] = {1, -1, 0, 0};
const int dir_c[4] = {0, 0, 1, -1};

int n, m;
int visited[MAXN][MAXN];
bool is_waypoint[MAXN][MAXN];
int grid[MAXN][MAXN];
Cell start;
int total_waypoints = 0;

bool can_reach_all_waypoints(int d) {
  int waypoint_reached = 0;
  queue<Cell> q;
  visited[start.row][start.col] = d;
  q.push(Cell(start.row, start.col));

  while (q.size()) {
    int r = q.front().row;
    int c = q.front().col;
    q.pop();
    if (is_waypoint[r][c]) ++waypoint_reached;

    for (int dir = 0; dir < 4; ++dir) {
      int i = r + dir_r[dir];
      int j = c + dir_c[dir];
      if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] == d || abs(grid[i][j] - grid[r][c]) > d) continue;
      visited[i][j] = d;
      q.push(Cell(i, j));
    }
  }

  return waypoint_reached == total_waypoints;
}

int find_min_difficulty(int l, int r) {
  if (l == r) {
    return l;
  }
  int mid = l + (r - l) / 2;
  if (can_reach_all_waypoints(mid)) return find_min_difficulty(l, mid);
  return find_min_difficulty(mid + 1, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> m >> n;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> grid[i][j];
    }
  }

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> is_waypoint[i][j];
      if (is_waypoint[i][j]) {
        start.row = i;
        start.col = j;
        ++total_waypoints;
      }
    }
  }


  cout << find_min_difficulty(0, 2*1e9);

  return 0;
}


