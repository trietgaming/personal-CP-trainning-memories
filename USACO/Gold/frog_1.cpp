#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "";
const int MAXN = 1e5 + 1;

int dp[MAXN], stones[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> stones[i];
  }
  dp[2] = abs(stones[2] - stones[1]);
  for (int i = 3; i <= n; ++i) {
    dp[i] = min(abs(stones[i] - stones[i - 1]) + dp[i-1], abs(stones[i] - stones[i - 2]) + dp[i-2]);
  }

  cout << dp[n];

  return 0;
}


