#include <bits/stdc++.h>

using namespace std;

char matrix[2][500][50];

int main() {

  freopen("cownomics.in", "r", stdin);
  freopen("cownomics.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> matrix[0][i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> matrix[1][i][j];
    }
  }

  int res = 0;

  for (int i = 0; i < m; ++i) {
    for (int j = i + 1; j < m; ++j) {
      for (int k = j + 1; k < m; ++k) {
        unordered_map<string, bool> spot;
        for (int c = 0; c < n; ++c) {
          string s1;
          s1+= matrix[0][c][i];
          s1 += matrix[0][c][j];
          s1 +=matrix[0][c][k];

          spot[s1] = true;
        }
        for (int c= 0; c < n; ++c) {
          string s1;
          s1+= matrix[1][c][i];
          s1 += matrix[1][c][j];
          s1 +=matrix[1][c][k];

          if (spot[s1]) {
            --res;
            break;
          }
        }
        ++res;
      }
    }
  }

  cout << res;

  return 0;
}
