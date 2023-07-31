#include <bits/stdc++.h>

using namespace std;

const string FNAME = "herding";

int arr[3];

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  for (int i = 0 ; i < 3; ++i) {
    cin >> arr[i];
  }

  sort(arr, arr + 3);

  int minDis, maxDis;
  if (arr[1] - arr[0] == 1 && arr[2] - arr[1] == 1) {
    cout << 0 << endl << 0;
    return 0;
  } else if (arr[1] - arr[0] == 1) {
    minDis = min(arr[2] - arr[1] - 1, 2);
  } else if (arr[2] - arr[1] == 1) {
    minDis = min(arr[1] - arr[0] - 1, 2);
  } else {
    minDis = min({arr[2] - arr[1] - 1, arr[1] - arr[0] - 1, 2});
  }
  maxDis = max({arr[1] - arr[0] - 1, arr[2] - arr[1] - 1, minDis});

  cout << minDis << endl << maxDis;

  return 0;
}


