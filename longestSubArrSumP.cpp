#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXN = 500005;

ll arr[MAXN], mins[MAXN];
ll prefixSum[MAXN];

ll searchForInd(ll l, ll r, ll num) {
  ll ind = -1;
  while (l <= r) {
    ll m = (l + r) / 2;
    if (mins[m] <= num) {
      ind = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return ind;
}

int main() {

  ll n, p;
  cin >> n >> p;

  for (ll i = 1; i <= n; ++i) {
    cin >> arr[i];
  }

  prefixSum[0] = 0;
  mins[0] = LLONG_MAX;
  prefixSum[1] = mins[1] = arr[1];

  for (ll i = 2; i <= n; ++i) {
    prefixSum[i] = prefixSum[i-1] + arr[i];
    mins[i] = min(mins[i - 1], prefixSum[i]);
  }

  ll res = -1;

  for (ll i = 1; i <= n; ++i) {
    if (prefixSum[i] >= p) res = max(res, i);
    else {
      ll toFind = prefixSum[i] - p;
      ll ind = searchForInd(1, i, toFind);
      if (ind == -1) continue;
      res = max(res, i - ind);
    }
  }

  cout << (res <= 0? -1: res);

  return 0;
}
