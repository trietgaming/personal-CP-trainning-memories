#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "where";
const int MAXN = 20;

struct Rectangle {
  int top, left, bottom, right;
  Rectangle() {};
  Rectangle(int r1, int r2, int c1, int c2) {
    bottom = max(r1, r2);
    top = min(r1, r2);
    left = min(c1, c2);
    right = max(c1, c2);
  }
};

char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int connected[256];
int n;

vector<Rectangle> all_pcl;

void flood_fill(Rectangle &subgrid, int r, int c, char ch) {
  if (r < subgrid.top || r > subgrid.bottom || c < subgrid.left || c > subgrid.right || visited[r][c] || grid[r][c] != ch) return;
  visited[r][c] = true;

  flood_fill(subgrid, r + 1, c, ch);
  flood_fill(subgrid, r - 1, c, ch);
  flood_fill(subgrid, r, c + 1, ch);
  flood_fill(subgrid, r, c - 1, ch);
}

bool is_pcl(Rectangle subgrid) {
  for (int i = 0; i < n; ++i)
    fill(visited[i], visited[i] + n, false);

  for (int ch = 'A'; ch <= 'Z'; ++ch)
    connected[ch] = 0;

  for (int i = subgrid.top; i <= subgrid.bottom; ++i) {
    for (int j = subgrid.left; j <= subgrid.right; ++j) {
      if (!visited[i][j]) {
        flood_fill(subgrid, i, j, grid[i][j]);
        ++connected[grid[i][j]];
      }
    }
  }

  int distinct_connected = 0, more_than_2_components = 0;
  for (int ch = 'A'; ch <= 'Z'; ++ch) {
    if (connected[ch]) ++distinct_connected;
    if (connected[ch] >= 2) ++more_than_2_components;
  }

  return distinct_connected == 2 && more_than_2_components == 1;
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

  for (int i1 = 0; i1 < n; ++i1) {
    for (int j1 = 0; j1 < n; ++j1) {
      for (int i2 = 0; i2 < n; ++i2) {
        for (int j2 = 0; j2 < n; ++j2) {
          Rectangle rec(i1, j1, i2, j2);
          if (is_pcl(rec)) {
            all_pcl.push_back(rec);
          }
        }
      }
    }
  }

  vector<bool> is_valid_pcl;
  for (int i = 0; i < all_pcl.size(); ++i) {
    is_valid_pcl.push_back(true);
  }

  for (int i = 0; i < all_pcl.size(); ++i) {
    for (int j = i + 1; j < all_pcl.size(); ++j) {
      Rectangle &rec1 = all_pcl[i], &rec2 = all_pcl[j];
      if (rec1.top <= rec2.top && rec1.bottom >= rec2.bottom && rec1.left <= rec2.left && rec1.right >= rec2.right)
        is_valid_pcl[j] = false;
      else if (rec2.top <= rec1.top && rec2.bottom >= rec1.bottom && rec2.left <= rec1.left && rec2.right >= rec1.right)
        is_valid_pcl[i] = false;
    }
  }

  int res = 0;
  for (int i = 0; i < all_pcl.size(); ++i) {
    if (is_valid_pcl[i]) ++res;
  }

  cout << res;

  return 0;
}


