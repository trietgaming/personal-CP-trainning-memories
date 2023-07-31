#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "angry";
const int MAXN = 500000;

ll arr[MAXN];
ll n, k;

bool canDetonateAllWithThisR(ll r) {
  ll curPos = -1;
  for (int i = 1; i <= k && curPos < arr[n-1]; ++i) {
    ll xMinusR = *upper_bound(arr, arr + n, curPos);
    curPos = xMinusR + 2*r;
  }

  return curPos >= arr[n-1];
}

ll searchMinR(int l, int r) {
  if (l == r) return l;

  ll mid = l + (r - l) / 2;

  if (canDetonateAllWithThisR(mid))
    return searchMinR(l, mid);

  return searchMinR(mid + 1, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n >> k;

  for (int i = 0; i < n; ++i)
    cin >> arr[i];

  sort(arr, arr + n);

  cout << searchMinR(1, (arr[n-1] - arr[0]) / 2);

  return 0;
}


