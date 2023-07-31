#include <bits/stdc++.h>

using namespace std;

const int n = 3;

char grid[n][n];
bool cowWon[256], teamWon[256][256];
int resS = 0, resT = 0;

set<char> s;

void setProcess() {
  char maybeWon = *s.begin();
  if (s.size() == 1 && !cowWon[maybeWon]) {
    cowWon[maybeWon] = true;
    ++resS;
  }
  char teammate = *(--s.end());
  if (s.size() == 2 && !teamWon[maybeWon][teammate]) {
    teamWon[maybeWon][teammate] = true;
    ++resT;
  }
  s.clear();
}

int main() {

  freopen("tttt.in", "r", stdin);
  freopen("tttt.out", "w", stdout);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
        char &c = grid[i][j];
      cin >> c;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      s.insert(grid[i][j]);
    }
    setProcess();
    for (int j = 0; j < n; ++j) {
      s.insert(grid[j][i]);
    }
    setProcess();
  }


  for (int i = 0; i < n; ++i) {
    s.insert(grid[i][i]);
  }
  setProcess();
  for(int i = 0; i < n; ++i) {
    s.insert(grid[i][n - i - 1]);
  }
  setProcess();

  cout << resS << "\n" << resT;

  return 0;
}
