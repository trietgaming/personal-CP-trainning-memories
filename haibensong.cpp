#include <bits/stdc++.h>

using namespace std;
const string FILENAME = "haibensong";
const int MAXN = 101;

bool matrix[MAXN][MAXN];
vector<vector<int> > dp(MAXN, vector<int>(MAXN, 0));

int main() {

  ifstream inp(FILENAME + ".inp");
  int n;
  inp >> n;

  while (!inp.eof()) {
    int i, j;
    inp >> i >> j;
    matrix[i][j] = 1;
  }
  inp.close();

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = max(dp[i-1][j-1] + matrix[i][j], max(dp[i][j-1], dp[i-1][j]));
    }
  }

  stack<pair<int, int> > trace;

  int i = n, j = n;
  while (j > 0) {
    if (dp[i][j] != dp[i][j-1]) {
      trace.push(pair<int, int>(i, j));
      --i;
    }
    --j;
  }

  cout << dp[n][n] << endl;
  while (!trace.empty()) {
    pair<int, int> top = trace.top();
    trace.pop();
    cout << top.first << " " << top.second << endl;
  }

  return 0;
}
