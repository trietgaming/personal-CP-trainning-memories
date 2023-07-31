#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 100000;
const long long INF = LLONG_MAX;

long long n;
long long tree[MAXN*2];

void buildTree() {
  for (long long i = n - 1; i > 0; --i) {
    tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
  }
}

long long query(long long l, long long r) {
  if (r > n) r = n;
  long long res = -INF;
  for (l += n, r += n; l < r; l >>=1, r >>=1) {
    if (l & 1) res = max(res, tree[l++]);
    if (r & 1) res = max(res, tree[--r]);
  }
  return res;
}

void update(long long p, long long val) {
  for (tree[p += n] = val; p > 1; p >>= 1) {
    tree[p >> 1] = max(tree[p], tree[p^1]);
  }
}

int main() {

  cin >> n;
  long long k;
  cin >> k;

  for (long long i = 0; i < n; ++i) {
    cin >> tree[i + n];
  }

  buildTree();

//  for (int i = 0; i < 2 * n; ++i) cout << tree[i] << " ";
//  cout << endl;

  for (long long i = n - 2; i >= 0 ; --i) {
    long long maxSum = query(i + 1, i + k + 1);
    update(i, max(tree[i + n], maxSum + tree[i + n]));
  }

//  for (int i = start; i < n; ++i) {
//    cout << dp[i] << " ";
//  }
//  cout << endl;

  cout << (tree[1] < 0? 0: tree[1]);

  return 0;
}
