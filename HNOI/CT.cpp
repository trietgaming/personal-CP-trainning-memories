#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MAXN = 500 + 5, MAXO = 1e5 * 4 + 5, OFFSET = 1e5;
const string FNAME = "CT";

ll arr[MAXN];
ll dp[MAXN][MAXO];

ll &get(ll i, ll o) {
  return dp[i][o + OFFSET];
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen((FNAME + ".inp").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }

  for (int i = 0; i <= n + 1; ++i) fill(dp[i], dp[i] + MAXO, -100000000);

  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int o = 0; o < MAXO; ++o) {

      get(i, o) = max({get(i - 1, o), get(i-1, o + arr[i]) + arr[i], get(i-1, o - arr[i]) + arr[i]});

    }
  }
  ll res = get(n, 0);

  cout << res;
  cerr << res;

  return 0;
}
