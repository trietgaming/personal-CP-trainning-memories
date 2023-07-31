#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "";
const int MAXN = 1e6+1, MOD = 1e9 + 7;
ll arr[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;
  arr[0] = 1;
  for (int i = 1; i < 6; ++i) {
    arr[i] = arr[i - 1] * 2;
  }
  for (int i = 6; i < n; ++i) {
    arr[i] = arr[i-1] + arr[i-2] + arr[i - 3] + arr[i - 4] + arr[i - 5] + arr[i-6];
    arr[i] %= MOD;
  }

  cout << arr[n-1];


  return 0;
}


