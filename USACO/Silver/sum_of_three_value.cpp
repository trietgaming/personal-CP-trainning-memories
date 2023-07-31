#include <bits/stdc++.h>

using namespace std;

const string FNAME = "sum3equalK";
const int MAXN = 5000;

pair<long long, int> arr[MAXN];

int main() {

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  long long k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i].first;
    arr[i].second = i+1;
  }

  sort(arr, arr + n);

  for (int third = 0; third < n; ++third) {
    if (arr[third].first >= k) continue;
    long long sum = k - arr[third].first;
    int i = 0, j = n - 1;
    while (i < j) {
      long long sum2 = arr[i].first + arr[j].first;
      if (sum2 == sum) {
        if (i != third && j != third) {
          cout << arr[i].second << " " << arr[third].second  << " " << arr[j].second;
          return 0;
        }
        --j;
      }
      if (sum2 > sum) {
        --j;
      } else ++i;
    }
  }

  cout << "IMPOSSIBLE";

  return 0;
}


