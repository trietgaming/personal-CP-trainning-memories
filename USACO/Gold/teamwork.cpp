#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "teamwork";
const int MAXN = 10001;

int arr[MAXN], dp[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, k;
  cin >> n >> k;

  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }

  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    int cur_max = arr[i];
    for (int j = i, s = max(1, i - k + 1); j >= s; --j) {
      cur_max = max(cur_max, arr[j]);
      dp[i] = max(dp[i], cur_max * (i - j + 1) + dp[j - 1]);
    }
  }

  cout << dp[n];

  return 0;
}


