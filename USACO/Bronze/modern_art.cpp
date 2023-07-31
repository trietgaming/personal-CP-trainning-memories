#include <bits/stdc++.h>

using namespace std;

struct Point {
  int x, y;
};

// top-left, bottom-right
struct Rectangle {
  Point tl, br;
};

const string FNAME = "art";

int grid[10][10];
// 1 - 9
Rectangle colors[10];
bool isAppeared[10], isCovered[10];

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  // init colors
  for (int i = 1; i <= 9; ++i) {
    colors[i].tl.x = 11;
    colors[i].tl.y = 11;
    colors[i].br.x = -1;
    colors[i].br.y = -1;
  }

  int n; cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char c;
      int &cell = grid[i][j];
      cin >> c;
      cell = c - '0';
      if (cell) {
        isAppeared[cell] = true;
        colors[cell].tl.x = min(colors[cell].tl.x, j);
        colors[cell].tl.y = min(colors[cell].tl.y, i);
        colors[cell].br.x = max(colors[cell].br.x, j);
        colors[cell].br.y = max(colors[cell].br.y, i);
      }
    }
  }

  for (int color = 1; color <= 9; ++color) {
    if (isAppeared[color]) {
      for (int i = colors[color].tl.y; i <= colors[color].br.y; ++i) {
        for (int j = colors[color].tl.x; j <= colors[color].br.x; ++j) {
          if (grid[i][j] != color) {
            isCovered[grid[i][j]] = true;
          }
        }
      }
    }
  }

  int res = 0;

  for (int color = 1; color <= 9; ++color) {
    if (isAppeared[color] && !isCovered[color]) {
      ++res;
    }
  }

  cout << res;

  return 0;
}


