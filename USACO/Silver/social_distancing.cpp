#include <bits/stdc++.h>

using namespace std;
using ll = long long;
// true = closing
using pll = pair<ll, ll>;

const string FNAME = "socdist";
const int MAXN = 100000;

pll arr[MAXN + 1];
int n, m;

bool valid(ll dist) {
  ll curPos = arr[0].first;
  for (int cow = 1, i = 0; cow < n; ++cow) {
    while (i < m && curPos + dist > arr[i].second) {
      if (curPos + dist > arr[i].second && i == m - 1) return false;
      ++i;
    }
    curPos = max(curPos + dist, arr[i].first);
  }
  return true;
}

ll findMaxDist(ll l, ll r) {
  if (l == r) return r;

  ll mid = l + (r - l + 1) / 2;
  if (valid(mid))
    return findMaxDist(mid, r);
  return findMaxDist(l, mid - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    cin >> arr[i].first >> arr[i].second;
  }

  sort(arr, arr + m);
  arr[m + 1].first = -1;
  arr[m + 1].second = -1;

  cout << findMaxDist(1, (ll) 1e18);

  return 0;
}


