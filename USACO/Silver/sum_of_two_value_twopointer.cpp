#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;

pair<long long, int> arr[MAXN];

int main() {

  long long n, x;
  cin >> n >> x;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i].first;
    arr[i].second = i;
  }

  sort(arr, arr + n);

  int i = 0, j = n - 1;
  while (i < j && arr[i].first + arr[j].first != x) {
    if (arr[i].first + arr[j].first > x) --j;
    else ++i;
  }

  if (i == j) cout << "IMPOSSIBLE";
  else cout << arr[i].second + 1 << " " << arr[j].second + 1 ;

  return 0;
}


