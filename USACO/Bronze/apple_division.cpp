#include <bits/stdc++.h>

using namespace std;

int arr[20], n;
long long sum = 0, res = LLONG_MAX;

void calc(int i = 0, long long cur = 0){
  if (i == n - 1) {
    res = min(res, abs(2*cur - sum));
    return;
  }
  calc(i+1, cur + arr[i]);
  calc(i + 1, cur);
}

int main() {

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    sum += arr[i];
  }

  calc();

  cout << res;

  return 0;
}
