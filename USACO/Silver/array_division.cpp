#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "arrdiv";
const int MAXN = 200000;

int n, k, arr[MAXN];

bool canDivideKSubArr(ll sum) {
  ll curSum = 0, curSubArr = 1;
  for (int i = 0; i < n; ++i) {
    if (curSum + arr[i] <= sum) curSum += arr[i];
    else {
      if (arr[i] > sum) return false;
      curSum = arr[i];
      ++curSubArr;
    }
    if (curSubArr > k) return false;
  }
  return true;
}

ll findMinMaxSubArrSum(ll l, ll r) {
  if (l == r) return l;
  ll mid = l + (r - l) / 2;
  if (canDivideKSubArr(mid)) return findMinMaxSubArrSum(l, mid);
  return findMinMaxSubArrSum(mid + 1, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  cout << findMinMaxSubArrSum(0, (ll) 2*1e14);

  return 0;
}


