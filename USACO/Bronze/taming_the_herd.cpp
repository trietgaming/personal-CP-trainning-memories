#include <bits/stdc++.h>

using namespace std;

const string FNAME = "taming";

vector<int> arr(101);

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }

  // TH ngay 1 ko BO
  if (arr[1] > 0) {
    cout << -1;
    return 0;
  }

  for (int i = 1; i <= n; ++i) {
    if (arr[i] == -1) continue;
    int bo = i - arr[i];
    if (bo <= 0 || arr[bo] > 0) {
      cout << -1;
      return 0;
    }
    for (int j = bo, t = 0; j < i; ++j) {
      arr[j] = t++;
    }

  }

  arr[1] = 0;
  int minRes = 0;

  for (int i = 1; i <= n; ++i) {
    if (arr[i] == 0) ++minRes;
  }

  int maxRes = minRes;
  for (int i = 1; i <= n; ++i) {
    if (arr[i] == -1) ++maxRes;
  }

  cout << minRes << " " << maxRes;

  return 0;
}


