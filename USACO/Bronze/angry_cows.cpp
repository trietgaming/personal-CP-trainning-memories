#include <bits/stdc++.h>

using namespace std;

const string FNAME = "angry";

long long arr[100];

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  int res = 0;
  for (int best = 0; best < n; ++best) {
    int l = best, r = best;
    for (long long t = 1, last = arr[best]; l >= 1; ++t) {
      if (arr[l-1] < arr[l] - t) break;
      while (l >= 1 && arr[l-1] >= last - t) --l;
      last = arr[l];
    }
    for (long long t = 1, last = arr[best]; r < n - 1; ++t) {
      if (arr[r+1] > arr[r] + t) break;
      while (r < n - 1 && arr[r+1] <= last + t) ++r;
      last = arr[r];
    }

    res = max(res, r - l + 1);
  }

  cout << res;

  return 0;
}


