#include <bits/stdc++.h>

using namespace std;

const string FNAME = "spacedout";

const int MAXN = 1000;

int grid[MAXN][MAXN];

int main() {

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> grid[i][j];
    }
  }

  int maxRow = 0;
  for (int i = 0; i < n; ++i) {
    int odd = 0, even = 0;
    for (int j = 0; j < n; j+= 2) {
      even += grid[i][j];
    }
    for (int j = 1; j < n; j+= 2) {
      odd += grid[i][j];
    }
    maxRow += max(odd, even);
  }

  int maxCol = 0;
  for (int i = 0; i < n; ++i) {
    int odd = 0, even = 0;
    for (int j = 0; j < n; j+= 2) {
      even += grid[j][i];
    }
    for (int j = 1; j < n; j+= 2) {
      odd += grid[j][i];
    }
    maxCol += max(odd, even);
  }

  cout << max(maxCol, maxRow);

  return 0;
}


