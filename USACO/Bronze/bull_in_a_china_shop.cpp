/*

  Main idea:
  Get the highest, lowest, left most, right most position of the "#" character
  With every piece, move it to all possible position with 4 direction: up, down, left, right (using BFS)
    A position is possible when the moved '#' position is still in the grid (>=0 && < n)
    We will not store the position of all the pieces' '#' character directly but store its distance to the original position of the piece
    for better time and memory complexity
    Check if the moved piece match 100% some part of the original grid => store it in a vector called ePieces
    Store all the pieces that suitable (same pieces with different positions will also be stored)
  Loop through all combination of suitable ePieces (ignore all same pieces)
    Check if they have the same position that has '#' character => intersected => skip
    if not, fill all their '#' character to another temporary grid
    Check if the temporary grid is exactly the same as the original grid => print out the result and exit

*/
#include <bits/stdc++.h>

using namespace std;

struct Move {
  // piece Id, moved x, moved y
  int pid, mx, my;
  Move(int i, int x, int y) {
    pid = i;
    mx = x;
    my = y;
  }
};

const int MAXN = 8, MAXK = 10;

int n, k;
char original[MAXN][MAXN];
char pieces[MAXK][MAXN][MAXN];

const int dirX[4] = {0, 0, -1, 1},
          dirY[4] = {-1, 1, 0, 0};

// 0 - up, 1 - down, 2 - left, 3 - right;
// (highest #, lowest #, left most #, right most #)
int bounds[MAXK][4];

// using map for negative-indexed
unordered_map<int, unordered_map<int, bool>> visited[MAXK];
int fillMatrix[MAXN][MAXN];
vector<Move> ePieces;

bool isAPartOfOriginal(Move& m) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i + m.my < 0 || i + m.my >= n || j + m.mx < 0 || j + m.mx >= n) continue;
      if (pieces[m.pid][i][j] == '#' && original[i + m.my][j + m.mx] == '.') {
        return false;
      };
    }
  }
  return true;
}

bool fillAndCheckIntersection(Move &piece, int cId, int interCheckId) {
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      if (y + piece.my < 0 || y + piece.my >= n || x + piece.mx < 0 || x + piece.mx >= n)
        continue;
      int fillY = piece.my + y, fillX = piece.mx + x;
      if (original[fillY][fillX] == '#' && pieces[piece.pid][y][x] == '#') {
        if (fillMatrix[fillY][fillX] == interCheckId) {
          return true;
        }
        fillMatrix[fillY][fillX] = cId;
      }
    }
  }
  return false;
}

bool isFilledMatrixAndOriginalMatched(int iId, int jId) {
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      if (fillMatrix[y][x] != iId && fillMatrix[y][x] != jId && original[y][x] == '#') {
        return false;
      }
    }
  }
  return true;
}

int main() {

  freopen("bcs.in", "r", stdin);
  freopen("bcs.out", "w", stdout);

  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> original[i][j];
    }
  }

  //init bound ;
  for (int i = 0; i < MAXK; ++i) {
    bounds[i][0] = 11;
    bounds[i][1] = 0;
    bounds[i][2] = 11;
    bounds[i][3] = 0;
  }

  for (int p = 0; p < k; ++p) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> pieces[p][i][j];
        if (pieces[p][i][j] == '#') {
          bounds[p][0] = min(bounds[p][0], i);
          bounds[p][1] = max(bounds[p][1], i);
          bounds[p][2] = min(bounds[p][2], j);
          bounds[p][3] = max(bounds[p][3], j);
        }
      }
    }
  }

  queue<Move> q;
  for (int i = 0; i < k; ++i) {
    q.push(Move(i, 0, 0));
  }

  // BFS
  while (!q.empty()) {
    Move &fr = q.front();
    if (isAPartOfOriginal(fr)) {
      ePieces.push_back(fr);
    }

    for (int i = 0; i < 4; ++i) {
      int nextX = fr.mx + dirX[i];
      int nextY = fr.my + dirY[i];
      if (visited[fr.pid][nextY][nextX] ||
          bounds[fr.pid][0] + nextY < 0 || bounds[fr.pid][0] + nextY >= n ||
          bounds[fr.pid][1] + nextY < 0 || bounds[fr.pid][1] + nextY >= n ||
          bounds[fr.pid][2] + nextX < 0 || bounds[fr.pid][2] + nextX >= n ||
          bounds[fr.pid][3] + nextX < 0 || bounds[fr.pid][3] + nextX >= n ) continue;
      visited[fr.pid][nextY][nextX] = true;
      q.push(Move(fr.pid, nextX, nextY));
    }
    q.pop();
  }

  int iId = 1, jId = INT_MIN;
  for (int i = 0; i < ePieces.size(); ++i, ++iId) {
    // fill I then check J and I, i and INT_MAX will never matched => completely filled I
    fillAndCheckIntersection(ePieces[i], iId, INT_MAX);

    for (int j = 0; j < ePieces.size(); ++j, ++jId) {
      if (i == j || ePieces[i].pid == ePieces[j].pid) continue;

      bool intersect = false;

      if (fillAndCheckIntersection(ePieces[j], jId, iId) || !isFilledMatrixAndOriginalMatched(iId, jId)) continue;

      cout << ePieces[i].pid + 1 << " " << ePieces[j].pid + 1;
      return 0;

    }
  }

  return 0;
}
