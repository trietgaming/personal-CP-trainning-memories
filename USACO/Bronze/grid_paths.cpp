#include <iostream>

using namespace std;
/*
  0 - up
  1 - down
  2 - left
  3 - right
*/

const int n = 48;
char inPath[n + 1];
bool unavailable[n+1][4], grid[9][9];

const int mx[4] = {0, 0, -1, 1};
const int my[4] = {-1, 1, 0, 0};
int dirLookUp[256];

int res = 0;

void backtrack(int moved = 1, int cx = 1, int cy = 1) {
  if (cx == 1 && cy == 7) {
    if (moved == n + 1) {
      ++res;
    }
    return;
  }
  if (moved == n + 1) return;
  if (
        (grid[cy - 1][cx] &&  grid[cy + 1][cx])
        && !grid[cy][cx - 1] && !grid[cy][cx + 1]
      ) return;
  if (
        grid[cy][cx - 1] && grid[cy][cx + 1]
        && !grid[cy - 1][cx] && !grid[cy + 1][cx]
      )
       return;
  if (inPath[moved] != '?') {
    int dir = dirLookUp[inPath[moved]];
    int nx = cx + mx[dir];
    int ny = cy + my[dir];
    if (nx < 1 || nx > 7 || ny < 1 || ny > 7 || grid[ny][nx]) return;
    grid[ny][nx] = true;
    backtrack(moved + 1, nx, ny);
    grid[ny][nx] = false;
    return;
  }
  ++moved;
  for (int dir = 0; dir < 4; ++dir) {
    int nx = cx + mx[dir];
    int ny = cy + my[dir];
    if (nx < 1 || nx > 7 || ny < 1 || ny > 7 || grid[ny][nx]) continue;
    grid[ny][nx] = true;
    backtrack(moved, nx, ny);
    grid[ny][nx] = false;
  }
}

int main() {

//  freopen("paths.in", "r", stdin);

  for (int i = 1; i <= n; ++i) {
    cin >> inPath[i];
  }

  dirLookUp['U'] = 0;
  dirLookUp['D'] = 1;
  dirLookUp['L'] = 2;
  dirLookUp['R'] = 3;

  grid[1][1] = true;
  for (int i = 1; i <= 7; ++i) {
    grid[0][i] = true;
    grid[8][i] = true;
    grid[i][0] = true;
    grid[i][8] = true;
  }
  backtrack();

  cout << res;

  return 0;
}
