#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "";
const int MAXN = 2*1e5;

bool arr[MAXN];
int dp1[MAXN], dp2[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }

    dp1[0] = arr[0];
    dp1[1] = arr[0] + arr[1];
    dp2[0] = 1e9;
    dp2[1] = dp1[0];
    for (int i = 2; i < n; ++i) {
      dp1[i] = min(dp2[i-1], dp2[i - 2] + arr[i - 1]) + arr[i];
      dp2[i] = min(dp1[i-1], dp1[i-2]);
    }

//    for (int i = 0; i < n; ++i) {
//      cout << dp1[i] << " ";
//    }
//    cout << "\n";
//    for (int i = 0; i < n; ++i) {
//      cout << dp2[i] << " ";
//    }
//    cout << "\n----------------------\n";

    cout << min(dp1[n-1], dp2[n-1]) << "\n";
  }

  return 0;
}


