#include <bits/stdc++.h>

using namespace std;

const int n = 8;

vector<bool> rows(n, false), cols(n, false), rCross(2*n, false), lCross(2*n, false);
vector<vector<bool>> reserved(n, vector<bool>(n, false));

void placeQueen(int col, int &total) {
  if (col == n) {
    ++total;
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (reserved[i][col] || rows[i] || cols[i] || rCross[i - col + 8] || lCross[i + col + 8]) continue;
    rows[i]  = true;
    cols[i] = true;
    rCross[i - col + 8] = true;
    lCross[i + col + 8] = true;

    placeQueen(col + 1, total);

    rows[i]  = false;
    cols[i] = false;
    rCross[i - col + 8] = false;
    lCross[i + col + 8] = false;
  }
}

int main() {

  char temp;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> temp;
      if (temp == '*') reserved[i][j] = true;
    }
  }

  int total = 0;
  placeQueen(0, total);

  cout << total;

  return 0;
}
