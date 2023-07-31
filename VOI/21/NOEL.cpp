#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "NOEL";
const int INF = 1e9 + 7;
const int MAXN = 2002;

ll n, d;

ll arr[MAXN];

/// SUBTASK 1
vector<ll> cur;
ll res = 0;
void check() {
  for (int i = 0, e = (ll) cur.size() / 2; i < e; ++i) {
    if (abs(cur[i] - cur[i + e]) > d) return;
  }
  res = max(res, (ll) cur.size() / 2);
}
void backtrack(int ind) {
  if (cur.size() % 2 == 0) {
    check();
  }
  if (ind > 2*n) return;
  cur.push_back(arr[ind]);
  backtrack(ind + 1);
  cur.pop_back();
  backtrack(ind + 1);
}

ll dp[MAXN][MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".inp").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n >> d;
  ll n2 = 2 * n;
  for (int i = 1; i <= n2; ++i) {
    cin >> arr[i];
  }


  if (n <= 10) {
    backtrack(1);
    return 0;
  }

  if (n <= 500) {
    for (int r = 2; r <= n2; ++r) {
      for (int i = 0; i <= n2; ++i) fill(dp[i], dp[i] + n2 + 1, 0);
      for (int i = 1; i < r; ++i) {
        for (int j = r; j <= n2; ++j) {
          dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1] + (abs(arr[i] - arr[j]) <= d)});
        }
      }
      res = max(res, dp[r - 1][n2]);
    }
  }



  cerr << res;
  cout << res;

  return 0;
}


