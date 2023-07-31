#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int BASE = 311, MAXN = 50010;
ll pows[MAXN], hashes[MAXN], r_hashes[MAXN];
int n;

ll getHash(int s, int e) {
  return (hashes[e + 1] - hashes[s] * pows[e-s+1] + MOD * MOD) % MOD;
}

ll getrHash(int s, int e) {
  return (r_hashes[n-s] - r_hashes[n-e - 1] * pows[e-s+1] + MOD * MOD) % MOD;
}

bool palindromeExist(int len) {
  for (int i = 0; i + len - 1 < n; ++i) {
    if (getHash(i, i + len - 1) == getrHash(i, i + len - 1)) return true;
  }
  return false;
}

int main() {

  string s;
  cin >> n >> s;

  pows[0] = 1;
  hashes[0] = r_hashes[0] = 0;
  for (int i = 1; i <= n; ++i) {
    hashes[i] = (hashes[i-1] * BASE + s[i-1]) % MOD;
    r_hashes[i] = (r_hashes[i-1] * BASE + s[n-i]) % MOD;
    pows[i] = (pows[i-1] * BASE) % MOD;
  }

  int lo = 1, hi = n - (n % 2 == 0);
  while(lo < hi) {
      int mid = (lo + hi) / 2;
      if (mid % 2 == 0) ++mid;
      if (palindromeExist(mid)) lo = mid;
      else hi = mid - 2;
  }
  int res = lo;
  lo = 0; hi = n - (n & 1);
  while(lo < hi) {
      int mid = (lo + hi) / 2;
      if (n & 1) ++mid;
      if (palindromeExist(mid)) lo = mid;
      else hi = mid - 2;
  }

  cout << max(res, lo);

  return 0;
}
