#include <bits/stdc++.h>

using namespace std;

const string FNAME = "cowtip";

bool grid[100][100];

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char c;
      cin >> c;
      grid[i][j] = c - '0';
    }
  }

  int res = 0;

  while (true) {
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j]) {
          if (i + j > x + y) {
            x = j;
            y = i;
          }
        }
      }
    }
    if (!x && !y) {
      if (grid[x][y] == 1) ++res;
      break;
    }
    for (int i = 0; i <= y; ++i) {
      for (int j = 0; j <= x; ++j) {
        grid[i][j] = !grid[i][j];
      }
    }
    ++res;
  }

  cout << res;

  return 0;
}


