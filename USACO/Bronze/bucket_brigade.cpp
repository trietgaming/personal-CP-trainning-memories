#include <bits/stdc++.h>
using namespace std;

char grid[10][10];
bool visited[10][10];
int mx[4] = {0, 0, -1, 1};
int my[4] = {1, -1, 0, 0};

struct cow {
  int distance;
  int x;
  int y;
  cow(int _x, int _y, int d) {
    distance = d;
    x = _x;
    y = _y;
  }
};

int main() {

  freopen("buckets.in", "r", stdin);
  freopen("buckets.out", "w", stdout);

  queue<cow> q;
  memset(visited, false, 10*10);

  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      cin >> grid[i][j];
      if (grid[i][j] == 'B') {
        q.push(cow(j, i, 0));
      }
    }
  }

  int res = 0;

  while (!q.empty()) {
    cow &top = q.front();
    q.pop();
    visited[top.y][top.x] = true;
    if (grid[top.y][top.x] == 'L') {
      res = top.distance - 1;
      break;
    }
    if (grid[top.y][top.x] == 'R') continue;
    for (int i = 0; i < 4; ++i) {
      int nextX = top.x + mx[i];
      int nextY = top.y + my[i];
      if (nextX < 0 || nextX >= 10 || nextY < 0 || nextY >= 10 || visited[nextY][nextX])
        continue;
      q.push(cow(nextX, nextY, top.distance + 1));
    }
  }

  cout << res;

  return 0;
}
