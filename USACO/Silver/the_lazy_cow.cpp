#include <bits/stdc++.h>

using namespace std;

const string FNAME = "lazy";
const int MAXN = 402;

long long sumCol[MAXN][MAXN], arr[MAXN][MAXN];

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n; int k;
  cin >> n >> k;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> arr[i][j];
      sumCol[i][j] = sumCol[i-1][j] + arr[i][j];
    }
  }

  long long res = INT_MIN;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int left = max(1, j - k);
      int right = min(n, j + k);

      long long temp = 0;
      for (int col = left; col <= right; ++col) {
        int height = k - abs(col - j);
        temp += sumCol[min(n, i + height)][col] - sumCol[max(0, i - height - 1)][col];
      }
      res = max(res, temp);
    }
  }

  cout << res;

  return 0;
}


