#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "subsum1";
const int MAXN = 200001;

ll prefixSum[MAXN];

int main() {

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  ll k;
  cin >> n >> k;

  for (int i = 1; i <= n; ++i) {
    cin >> prefixSum[i];
    prefixSum[i] += prefixSum[i-1];
  }

  int i = 0, j = 1;
  ll res = 0;
  while (i < j) {
    ll sum = prefixSum[j] - prefixSum[i];
    if (sum == k) ++res;
    if (sum <= k && j < n) ++j;
    else {
      ++i;
      if (j == i && j < n) ++j;
    }
  }

  cout << res;

  return 0;
}


