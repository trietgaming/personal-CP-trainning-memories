#include <bits/stdc++.h>

using namespace std;

const string FNAME = "revegetate";
const int MAXN = 100, MAXM = 150;

// edges[i][j] = edges[j][i] = true if there is an edge between i and j
bool edges[MAXN + 1][MAXN + 1], unavailable[MAXN + 1][5];

int n, m;

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int v1, v2;
    cin >> v1 >> v2;

    edges[v1][v2] = true;
    edges[v2][v1] = true;
  }

  for (int i = 1; i <= n; ++i) {
    int num;
    for (num = 1; num <= 4; ++num) {
      if (!unavailable[i][num])
        break;
    }
    cout << num;
    for (int j = 1; j <= n; ++j) {
      if (!edges[i][j]) continue;
      unavailable[j][num] = true;
    }
  }

  return 0;
}


