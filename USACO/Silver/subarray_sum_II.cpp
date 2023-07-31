#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 200000;
const string FNAME = "subsum";

ll prefixSum[MAXN+1];
unordered_map<ll, ll> sumCount;

int main() {

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  ll n, x;
  cin >> n >> x;

  ll res = 0;

  for (int i = 1; i <= n; ++i) {
    cin >> prefixSum[i];
    prefixSum[i] += prefixSum[i-1];
    res += sumCount[prefixSum[i] - x];
    sumCount[prefixSum[i]]++;
  }

  cout << res + sumCount[x];

  return 0;
}


