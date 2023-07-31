#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "sabotage";
const int MAXN = 100001;

ll arr[MAXN], prefixSum[MAXN];
int n;

double findMinAvgWithLength(int l) {
  int toRemove = n - l;
  double res = 1e20;
  for (int i = 1 + toRemove; i < n; ++i) {
    res = min(res, ((double) prefixSum[n] - (prefixSum[i] - prefixSum[i - toRemove]))/l);
  }
  return res;
}

double findMinAvg(int l, int r) {
  if (l == r) return findMinAvgWithLength(l);
  int mid = (l + r) / 2;
  double lenL = findMinAvgWithLength(l), lenR = findMinAvgWithLength(r);
  if (lenL == lenR) return findMinAvgWithLength(mid);
  if (lenR > lenL) return findMinAvg(l, mid);
  if (mid == l) return findMinAvg(mid + 1, r);
  return findMinAvg(mid, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    prefixSum[i] = prefixSum[i-1] + arr[i];
  }

  double res = findMinAvg(2, n - 1);
  cout.precision(3);
  cout << fixed << res;

  return 0;
}


