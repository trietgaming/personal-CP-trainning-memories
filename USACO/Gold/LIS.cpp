#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "";
const int MAXN =2*1e5;

int arr[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  vector<int> res;

  for (int i = 0; i < n; ++i) {
    auto lo = lower_bound(res.begin(), res.end(), arr[i]);
    if (lo == res.end()) res.push_back(arr[i]);
    else *lo = arr[i];
  }

  cout << res.size();

  return 0;
}


