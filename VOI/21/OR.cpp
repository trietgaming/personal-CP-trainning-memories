#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "OR";
const int MOD = 1e9 + 7;
const int MAXN = 1000000 + 5;

vector<ll> dp[MAXN];
ll arr[MAXN];

ll add(ll a, ll b) {
  return (a + b) % MOD;
}

bool ith_bit(ll a, ll i) {
  return (1LL << i) & a;
}
void printBin(ll a) {
  for (int i = __lg(a); i >= 0; --i) {
    cerr << ith_bit(a, i);
  }
  cerr << "\n";
}


void calc(ll curBit, ll curNum, ll ai, ll fx, ll k) {
  if (curBit == -1) {
    dp[fx][k] = add(dp[fx][k], dp[curNum][k - 1]);
    return;
  }
  if ( ith_bit(ai, curBit) &&  (!ith_bit(fx, curBit)) ) return;
  if ( !ith_bit(ai, curBit) &&  ith_bit(fx, curBit) ) return calc(curBit - 1, curNum | (1 << curBit), ai, fx, k);
  calc(curBit - 1, curNum, ai, fx, k);
  calc(curBit - 1, curNum | (1 << curBit), ai, fx, k);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
#ifdef LIONELMESSI
  freopen((FNAME + ".inp").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);
#endif // LIONELMESSI

  ll n, k, L, R;
  cin >> n >> k >> L >> R;
  for (int i = 0; i <= R; ++i) {
    dp[i] = vector<ll>(k + 1);
  }

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    dp[arr[i]][0] = 1;
  }

  ll res = 0;

  for (int l = 1; l <= k; ++l) {
    for (int x = 0; x <= R; ++x) {
      for (int i = 0; i < n; ++i) {
        if (arr[i] > x) continue;
        calc(__lg(x), 0, arr[i], x, l);
      }
    }
  }
  for (int x = L; x <= R; ++x) {
    if (x % 3 == 0) res = add(res, dp[x][k]);
  }

  cout << res;

  return 0;
}


