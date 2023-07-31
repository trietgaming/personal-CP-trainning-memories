#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "angry";
const int MAXN = 50000;

long double arr[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  int i = 1, j = n-2;
  long double maxR = (arr[n-1] - arr[0])/2, minR = 0;
  while (i < j) {
//      cout << i << "-" << j << endl;
    long double mid = minR + (maxR - minR)/2;
    if (arr[i] + mid >= arr[j] - mid && arr[i] - mid + 1 <= arr[i-1] && arr[j] + mid - 1 >= arr[j+1]) {
      maxR = mid;
    }
    else minR = mid;
    ++i;
    --j;
  }
  if (n & 1) {
    if (arr[i + 1] - arr[i] <= arr[i] - arr[i-1]) --i;
    else ++j;
  }
  long double mid = minR + (maxR - minR)/2;
  for (int a = 0; a < 100; ++a) {
//      cout << minR << " " << maxR << "\n";
    if (arr[i] + mid < arr[j] - mid || arr[i] - mid + 1 > arr[i-1] || arr[j] + mid - 1 < arr[j+1]) {
      minR = mid;
    }
    else maxR = mid;
    mid = minR + (maxR - minR)/2;
  }

  cout.precision(1);
  cout << fixed << min(maxR, (long double) round(minR * 10) /10);

  return 0;
}


