#include <bits/stdc++.h>

using namespace std;

int main() {

//  freopen("kayaking.in", "r", stdin);

  vector<int> arr;
  int n; cin >> n;

  for (int i = 0, temp; i < 2*n; ++i) {
    cin >> temp;
    arr.push_back(temp);
  }

  int res = INT_MAX;

  sort(arr.begin(), arr.end());

  vector<int> needPair = arr;
  for (int r1 = 0; r1 < 2*n; ++r1) {
    for (int r2 = r1 + 1; r2 < 2*n; ++r2) {
      vector<int> needPair;
      for (int i = 0; i < 2*n; ++i) {
        if (i == r1 || i ==r2) continue;
        needPair.push_back(arr[i]);
      }
      int temp = 0;
      for (int i = 0; i < 2*n - 3; i+=2) {
        temp += needPair[i+1] - needPair[i];
      }
      res = min(res, temp);
    }
  }

  cout << res;

  return 0;
}
