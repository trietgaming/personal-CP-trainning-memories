#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "convention";
const int MAXN = 100000;

int arr[MAXN];
int n, m, c;

bool isThisTimeALowerBoundOfMax(int w) {
  for (int i = 1, curBus = 1, firstCowOnBus = 0; i < n; ++i) {
    if (arr[i] - arr[firstCowOnBus] > w || i - firstCowOnBus + 1 > c) {
      if (curBus == m) return false;
      ++curBus;
      firstCowOnBus = i;
    }
  }
  return true;
}

int searchMinMaxWaitTime(int l, int r) {
  if (l == r) {
    return l;
  }
  int mid = (l + r) / 2;
  if (isThisTimeALowerBoundOfMax(mid))
    return searchMinMaxWaitTime(l, mid);
  return searchMinMaxWaitTime(mid + 1, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n >> m >> c;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  int res = searchMinMaxWaitTime(0, arr[n-1] - arr[0]);

  cout << res;

  return 0;
}


