#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "";
const int MAXN = 200000;

ll n, t;
ll arr[MAXN];

bool canMakeAtLeastTProducts(ll time) {
  ll p = 0;
  for (ll i = 0; i < n; ++i) {
    p += time / arr[i];
    if (p >= t) return true;
  }
  return p >= t;
}

ll findMinTime(ll l, ll r) {
  if (l == r) return l;
  ll mid = (l + r) / ((ll) 2);
  if (canMakeAtLeastTProducts(mid)) return findMinTime(l, mid);
  return findMinTime(mid + 1, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n >> t;
  for (ll i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  cout << findMinTime(0, (ll) 1e18);

  return 0;
}


