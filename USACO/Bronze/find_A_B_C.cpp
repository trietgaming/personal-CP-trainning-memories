#include <bits/stdc++.h>

using namespace std;

int arr[7];
const int n = 7;

int main() {

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  cout << arr[0] << " " << arr[1] << " " << arr[6] - (arr[0] + arr[1]);


  return 0;
}
