#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;

// base 1 indexed
int arr[MAXN + 1], prefixSum[MAXN + 1];

// [l, r]
int getSum(int l, int r) {
  return prefixSum[r] - prefixSum[l - 1];
}

void process() {
  int n; cin >> n;
  int res = n - 1;

  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    prefixSum[i] = prefixSum[i-1] + arr[i];
  }

  for (int r = 2; r <= n; ++r) {
    if (prefixSum[n] % r != 0) continue;
    int s = prefixSum[n] / r;
    int l = 1, counter = 0;
    bool valid = true;

    for (int i = 1; i <=n ; ++i) {
      int sumRange = getSum(l, i);
      if (sumRange == s) {
        counter += i - l;
        l = i + 1;
        continue;
      }
      if (sumRange > s) {
        valid = false;
        break;
      }
    }

    if (valid) res = min(res, counter);
  }

  cout << res << "\n";

}

int main() {

//  freopen("sleeping.in", "r", stdin);

  int t; cin >> t;

  while (t--) {
    process();
  }

  return 0;
}
