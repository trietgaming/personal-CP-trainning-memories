#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "countcross";
const int MAXN = 101;

struct Cell {
  int row, col, cow;
  Cell(int r = -1, int c = -1, int co = 0) {
    row = r;
    col = c;
    cow = co;
  }
};

// Cow x at i, j = grid[i][j]
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN][MAXN], reached[MAXN][MAXN];
bool unavailable_dir[MAXN][MAXN][4];
// 0 - up, 1 - down, 2 - left, 3 - right
const Cell dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, k, r;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n >> k >> r;
  while (r--) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    switch (r2 - r1) {
      case 0:
        switch (c2 - c1) {
          case -1:
            unavailable_dir[r1][c1][2] = true;
            unavailable_dir[r2][c2][3] = true;
            break;
          case 1:
            unavailable_dir[r1][c1][3] = true;
            unavailable_dir[r2][c2][2] = true;
            break;
        }
        break;
      case -1:
        unavailable_dir[r1][c1][0] = true;
        unavailable_dir[r2][c2][1] = true;
        break;
      case 1:
        unavailable_dir[r1][c1][1] = true;
        unavailable_dir[r2][c2][0] = true;
        break;
    }
  }

  queue<Cell> q;
  for (int i = 1; i <= k; ++i) {
    int r, c;
    cin >> r >> c;
    grid[r][c] = i;
    q.push({r, c, i});
  }

  int pairs_can_visit_each_without_cross_road = 0;
  while (!q.empty()) {
    Cell c = q.front();
    q.pop();
    if (c.row < 1 || c.row > n || c.col < 1 || c.col > n || visited[c.row][c.col][c.cow]) continue;
    visited[c.row][c.col][c.cow] = true;
    if (grid[c.row][c.col] && grid[c.row][c.col] != c.cow && !reached[c.cow][grid[c.row][c.col]]) {
      ++pairs_can_visit_each_without_cross_road;
      reached[c.cow][grid[c.row][c.col]] = true;
      reached[grid[c.row][c.col]][c.cow] = true;
    }
    for (int i = 0; i < 4; ++i) {
      if (unavailable_dir[c.row][c.col][i]) continue;
//      cout << c.row << " " << c.col << ", dir: " << i << endl;
      q.push({c.row + dir[i].row, c.col + dir[i].col, c.cow});
    }
  }

  cout << (k*k-k)/2 - pairs_can_visit_each_without_cross_road;

  return 0;
}


