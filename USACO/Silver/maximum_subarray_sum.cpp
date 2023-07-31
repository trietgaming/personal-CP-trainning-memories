#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "maxsubsum";
const int MAXN = 200000;

ll arr[MAXN + 2];
int minInd[MAXN + 2];

int main() {

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n; cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    arr[i] += arr[i-1];
    if (!minInd[i]) minInd[i] = minInd[i-1];
    if (arr[i] < arr[minInd[i]]) minInd[i+1] = i;
  }

  ll res = LLONG_MIN;

  for (int i = 1; i <= n; ++i) {
    res = max(res, arr[i] - arr[minInd[i]]);
  }

  cout << res;

  return 0;
}


