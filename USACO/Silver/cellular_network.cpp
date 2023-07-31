#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "cellular";
const int MAXN = 100001;

int n, m;
ll cities[MAXN], towers[MAXN];

bool allCitiesWithin(ll r) {
  ll left = towers[0] - r, right = towers[0] + r;
  ll curTower = 0;
  for (int i = 0; i < n; ++i) {
    if (cities[i] < left) return false;
    if (cities[i] > right) {
      while (curTower < m && cities[i] > right) {
        ++curTower;
        left = towers[curTower] - r;
        right = towers[curTower] + r;
        if (cities[i] < left) return false;
      }
      if (curTower == m) return false;
    }
  }
  return true;
}

ll findMinRadius(ll l, ll r) {
  if (l == r) return l;
  int mid = l + (r - l) / 2;
  if (allCitiesWithin(mid)) return findMinRadius(l, mid);
  return findMinRadius(mid + 1, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> cities[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> towers[i];
  }

  sort(cities, cities + n);
  sort(towers, towers + m);
  towers[m] = LLONG_MIN;

  cout << findMinRadius(0, INT_MAX);

  return 0;
}


