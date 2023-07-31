#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "maxmed";
const int MAXN = 200000;

int n, k;
int arr[MAXN];

bool canValBeMedian(int val) {
  ll totalOperations = 0;
  for (int i = n/2; i < n; ++i) {
    totalOperations += max(0, val - arr[i]);
  }
  return totalOperations <= (ll)k;
}

int searchMedian(int arr[], int lo, int hi) {
  if (lo == hi) return lo;
  int mid = lo + (hi - lo + 1) / 2;
  if (canValBeMedian(mid)) return searchMedian(arr, mid, hi);
  return searchMedian(arr, lo, mid - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  cout << searchMedian(arr, arr[n/2], 2000000000);

  return 0;
}


