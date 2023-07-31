#include <bits/stdc++.h>

using namespace std;

#define MAXN 200000

int n;
int arr[MAXN];
int mp[MAXN];

int main() {

  ifstream inp("MAXREM.inp");
  inp >> n;
  for (int i = 0; i < n; ++i) {
    inp >> arr[i];
  }

  inp.close();

  sort(arr, arr + n);

  int res = INT_MIN;

  for (int j = n - 2; j >= 0; --j) {
      if (res >= arr[j])
          break;

      if (arr[j] == arr[j + 1])
          continue;

      for (int i = 2 * arr[j]; i <= arr[n - 1] + arr[j]; i += arr[j]) {
          int ind = lower_bound(arr, arr + n, i) - arr;

          res = max(res, arr[ind - 1] % arr[j]);
      }
  }

  cout << res;

  return 0;
}
