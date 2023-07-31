#include <bits/stdc++.h>

using namespace std;

int arr[200001];

int main() {

  long long n, k;
  cin >> n >> k;
  unordered_map<int, int> mp;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    mp[arr[i]] = i;
  }

  bool impossible = true;

  for (int i = 1; i <= n; ++i) {
    int ind = mp[k - arr[i]];
    if (ind && ind != i) {
      impossible = false;
      cout << i << " " << mp[k - arr[i]];
      break;
    }
  }

  if (impossible) cout << "IMPOSSIBLE";

  return 0;
}
