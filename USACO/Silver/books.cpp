#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "books";
const int MAXN = 100000;

ll arr[MAXN];

int main() {

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  ll n, t;
  cin >> n >> t;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int res = 0;
  int i = 0, j = 0, cur = 0;
  while (i < n && j < n) {
    while (j < n) {
      cur += arr[j++];
      if (cur > t) {
        cur -= arr[--j];
        break;
      }
    }
    res = max(res, j - i);
    cur -= arr[i++];
  }

  cout << res;

  return 0;
}


