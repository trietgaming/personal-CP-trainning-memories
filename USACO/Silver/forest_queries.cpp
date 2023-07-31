#include <bits/stdc++.h>

using namespace std;

const string FNAME = "2dprefix";
const int MAXN = 1010;

int prefixSum[MAXN][MAXN];

int main() {

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, q;
  cin >> n >> q;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      char c;
      cin >> c;
      prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + (c == '*');
    }
  }

  while (q--) {
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    cout << prefixSum[y2][x2] - prefixSum[y1-1][x2] - prefixSum[y2][x1-1] + prefixSum[y1-1][x1-1] << "\n";
  }

  return 0;
}


