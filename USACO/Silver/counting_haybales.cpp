#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "haybales";
const int MAXN = 100000;

int arr[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << upper_bound(arr, arr + n, r) - lower_bound(arr, arr + n, l) << "\n";
  }

  return 0;
}


