#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "";
const int MAXN = 1000;

int n, m;
char grid[MAXN][MAXN];
bool visited[MAXN][MAXN];

const int dirx[4] = {1, -1, 0, 0};
const int diry[4] = {0, 0, 1, -1};

void flood_fill(int r, int c) {
  queue<pair<int, int>> q;
  q.push(make_pair(r, c));

  while (!q.empty()) {
    int r = q.front().first;
    int c = q.front().second;
    q.pop();

    if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] != '.' || visited[r][c]) continue;
    visited[r][c] = true;

    for (int dir = 0; dir < 4; ++dir) {
      q.push(make_pair(r + diry[dir], c + dirx[dir]));
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int res = 0;
  cin >> n >> m;
  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      cin >> grid[r][c];
    }
  }

  for (int r = 0; r < n; ++r) {
    for (int c = 0; c < m; ++c) {
      if (grid[r][c] == '#' || visited[r][c]) continue;
      flood_fill(r, c);
      ++res;
    }
  }

  cout << res;

  return 0;
}


