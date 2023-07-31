#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "";
const int MAXN = 200000;

int arr[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  vector<int> res;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  for (int i = 0; i < n; ++i) {
    int upInd = upper_bound(res.begin(), res.end(), arr[i]) - res.begin();
    if (upInd == res.size()) res.push_back(arr[i]);
    else res[upInd] = arr[i];
  }

  cout << res.size();

  return 0;
}


