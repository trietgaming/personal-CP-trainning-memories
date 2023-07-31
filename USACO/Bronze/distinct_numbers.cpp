#include <bits/stdc++.h>

using namespace std;

int arr[200000];

int main() {

  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  int res = 1;

  for (int i = 1; i < n; ++i) {
    if (arr[i-1] != arr[i]) ++res;
  }

  cout << res;

  return 0;
}
