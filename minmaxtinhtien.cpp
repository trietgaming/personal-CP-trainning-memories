#include <bits/stdc++.h>

using namespace std;

int main() {

  int tests, n, k;
  long long arr[17001], res[17001];

  deque<long long> q;

  cin >> tests;

  while (tests--) {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    for (int i = k-1; i < n; ++i) {
      while (!q.empty() && arr[q.back()] >= arr[i]) q.pop_back();
      if (!q.empty() && q.front() <= i - k) q.pop_front();
      q.push_back(i);
      res[i] = arr[q.front()];
    }
    for (int i = k-1; i < n; ++i) cout << res[i] << " ";
    cout << endl;
    q.clear();
  }

  return 0;
}
