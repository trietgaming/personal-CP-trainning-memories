#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "perimeter";
const int MAXN = 1000;

struct Cell {
  int row, col;
  Cell ();
  Cell(int r, int c) {
    row = r;
    col = c;
  }
};

Cell operator + (const Cell &a, const Cell &b) {
  return Cell(a.row + b.row, a.col + b.col);
}

const Cell dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int n;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int res_area = 0, res_perimeter = 0;

void flood_fill(int r, int c, int &area, int &perimeter) {
  queue<Cell> q;
  q.push(Cell(r, c));

  while (q.size()) {
    Cell f = q.front();
    q.pop();
    if (f.row < 0 || f.row >= n || f.col < 0 || f.col >= n || grid[f.row][f.col] != '#') {
      ++perimeter;
      continue;
    }
    if (visited[f.row][f.col]) continue;

    visited[f.row][f.col] = true;
    ++area;

    for (int i = 0; i < 4; ++i) {
      q.push(f + dir[i]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> grid[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int area = 0, perimeter = 0;
      if (!visited[i][j] && grid[i][j] == '#') {
        flood_fill(i, j, area, perimeter);
        if (area > res_area) {
          res_area = area;
          res_perimeter = perimeter;
        } else if (area == res_area)
          res_perimeter = min(res_perimeter, perimeter);
      }
    }
  }

  cout << res_area << " " << res_perimeter;

  return 0;
}


