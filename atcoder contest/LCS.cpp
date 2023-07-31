#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 3000 + 5;

int dp[MAXN][MAXN];

void maximize(int &target, int val) {
  target = max(target, val);
}

int main() {

  string s, t;
  cin >> s >> t;
  int n = s.length(), m = t.length();
  s = " " + s;
  t = " " + t;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      if (s[i] == t[j]) {
         maximize(dp[i][j], dp[i-1][j-1] + 1);
      }
//      cout << dp[i][j] << " ";
    }
//    cout << endl;
  }

  string resRev = "";

  int i = n, j = m;
  while (i >= 1 && j >= 1) {
    if (s[i] == t[j] && dp[i][j] >= dp[i-1][j] && dp[i][j] >= dp[i][j-1]) {
      resRev += t[j--];
      --i;
    } else if (dp[i][j] > dp[i][j-1]) {
      --i;
    } else {
      --j;
    }
  }

  for (int i = resRev.length() - 1; i>=0; --i) {
    cout << resRev[i];
  }

  return 0;
}
