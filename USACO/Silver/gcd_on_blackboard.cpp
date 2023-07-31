#include <bits/stdc++.h>

using namespace std;

const string FNAME = "gcdboard";
const int MAXN = 100000;

int gcd(int a, int b) {
  if (b == 0) return a;
  if (b > a) return gcd(a, b % a);
  return gcd(b, a % b);
}

int prefixGcd[MAXN], suffixGcd[MAXN], arr[MAXN];

int main() {

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  if (n == 1) {
    cout << arr[0];

    return 0;
  }

  prefixGcd[0] = arr[0];
  for (int i = 1; i < n; ++i) prefixGcd[i] = gcd(prefixGcd[i - 1], arr[i]);
  suffixGcd[n - 1] = arr[n-1];
  for (int i = n-2; i >= 0; --i) suffixGcd[i] = gcd(suffixGcd[i + 1], arr[i]);

  int res = prefixGcd[n - 1];
  res = max(res, suffixGcd[1]);
  res = max(res, prefixGcd[n - 2]);

  for (int i = 1; i <= n - 2; ++i) {
    res = max(res, gcd(prefixGcd[i - 1], suffixGcd[i + 1]));
  }

  cout << res;

  return 0;
}


