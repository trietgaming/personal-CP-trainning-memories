#include <bits/stdc++.h>

using namespace std;

const string FNAME = "haystack";
const int MAXN = 1000000;

int events[MAXN], arr[MAXN];

int main() {

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, q;
  cin >> n >> q;

  while (q--) {
    int l, r;
    cin >> l >> r;
    ++events[l-1];
    --events[r];
  }

  int cur = 0;
  for (int i = 0; i < n; ++i) {
    arr[i] = (cur += events[i]);
  }

  sort(arr, arr + n);

  cout << arr[n/2];

  return 0;
}


