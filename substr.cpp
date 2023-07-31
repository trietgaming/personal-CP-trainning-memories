#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const unsigned long long MOD = 1000000007;
const int BASE = 31;
const ll MAXN = 1e6+1;

ll pows[MAXN], hashA[MAXN];

ll getHashFromT(int s, int e) {
  return (hashA[e + 1] - hashA[s] * pows[e - s + 1] + MOD * MOD) % MOD;
}

int main() {

  string a, b;
  cin >> a >> b;

  pows[0] = 1;
  for (int i = 1, e = a.length(); i <= e; ++i) {
    pows[i] = (pows[i - 1] * BASE) % MOD;
  }

  ll hashB = 0;
  for (int i = 0, e = b.length(); i < e; ++i) {
    hashB = (hashB * BASE + (b[i] -'a' + 1)) % MOD;
  }

  hashA[0] = 0;
  for (int i = 1, e = a.length(); i <= e; ++i) {
    hashA[i] = (hashA[i-1] * BASE + a[i-1] - 'a' + 1) % MOD;
  }

  for (int i = 0, e = a.length() - b.length(); i <= e; ++i) {
    if (hashB == getHashFromT(i, i + b.length() - 1))
      cout << i + 1 << " ";
  }

  return 0;
}
