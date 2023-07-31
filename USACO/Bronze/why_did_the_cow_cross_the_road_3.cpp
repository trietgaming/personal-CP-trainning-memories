#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const string FNAME = "cowqueue";

pii arr[100];

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i].first >> arr[i].second;
  }

  sort(arr, arr + n);

  int res = 0;
  for (int i = 0; i < n; ++i) {
    res = max(arr[i].first, res) + arr[i].second;
  }

  cout << res;

  return 0;
}


