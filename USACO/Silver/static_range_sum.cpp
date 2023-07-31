#include <bits/stdc++.h>

using namespace std;

const string FNAME = "";

long long arr[500001];

int main() {

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    arr[i] += arr[i-1];
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << arr[r] - arr[l] << endl;
  }

  return 0;
}

