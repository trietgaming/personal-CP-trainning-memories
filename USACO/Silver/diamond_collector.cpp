#include <bits/stdc++.h>

using namespace std;

const string FNAME = "diamond";
const int MAXN = 50000;

int arr[MAXN + 1], maxDiamondIfThisIsLeftMost[MAXN]; //include itself
int maxDiamondCollectedAfterThis[MAXN + 1];

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  int l = 0, r = 0;

  while (l <= r) {
    while (arr[r] - arr[l] <= k && r < n) {
      ++r;
    }
    maxDiamondIfThisIsLeftMost[l] = r - l;
    ++l;
    if (r < l && r < n) ++r;
  }

  int temp = 0;

  for (int i = n - 1; i >= 0; --i) {
    temp = max(temp, maxDiamondIfThisIsLeftMost[i]);
    maxDiamondCollectedAfterThis[i] = temp;
  }

  int res = 0;

  for (int i = 0; i < n; ++i) {
    res = max(res, maxDiamondIfThisIsLeftMost[i] + maxDiamondCollectedAfterThis[i + maxDiamondIfThisIsLeftMost[i]]);
  }

  cout << res;

  return 0;
}


