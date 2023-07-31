#include <bits/stdc++.h>

using namespace std;

const string FNAME = "hoofball";

int arr[102], reach[102];
// 0 - left, 1 - right
bool dir[102];

int distance(int a, int b) {
  return abs(a - b);
}

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);
  int n; cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
  }

  if (n <= 2) {
    cout << 1;
    return 0;
  }

  sort(arr + 1, arr + n + 1);
  arr[0] = INT_MAX;
  arr[n + 1] = INT_MAX;
  for (int i = 1; i <= n; ++i) {
    dir[i] = distance(arr[i - 1], arr[i]) > distance(arr[i], arr[i + 1]);
    if (dir[i]) {
      reach[i + 1]++;
    } else {
      reach[i - 1]++;
    }
  }

  dir[1] = true;
  dir[n] = false;

  int res = 0;
  if (!dir[2] && dir[3]) ++res;
  if (dir[n-1] && !dir[n-2]) ++res;
  for (int i = 3; i <= n - 3; ++i) {
    if (!dir[i - 1] && dir[i] && !dir[i+1] && dir[i + 2]) ++res;
  }
  cout << res + count(reach + 1, reach + 1 + n, 0);

  return 0;
}


