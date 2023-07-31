#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 1e5;

long long n, h;
long long lazy[MAXN] = {0};

long long arr[MAXN << 1];

void apply(long long p, long long val) {
  arr[p] += val;
  if (p >= n) return;
  lazy[p] += val;
}

void buildTree() {
  for (long long i = n - 1; i > 0; --i) {
    arr[i] = max(arr[i << 1], arr[i << 1 | 1]);
  }
}

void build(long long p) {
  while (p > 1) {
    p >>= 1;
    arr[p] = max(arr[p<<1], arr[p<<1|1]) + lazy[p];
  }
}

void push(long long p) {
  for (long long s = h; s > 0; --s) {
    long long i = p >> s;
    if (lazy[i] != 0) {
      apply(i << 1, lazy[i]);
      apply(i << 1 | 1, lazy[i]);
      lazy[i] = 0;
    }
  }
}

void updateinterval(long long l, long long r, long long val) {
  l += n, r += n;
  long long l0 = l, r0 = r;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) apply(l++, val);
    if (r&1) apply(--r, val);
  }
  build(l0);
  build(r0-1);
}

long long query(long long l, long long r) {
  long long res = LLONG_MIN;
  l += n; r += n;
  push(l);
  push(r - 1);
  for (; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, arr[l++]);
    if (r&1) res = max(res, arr[--r]);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  h = ceil(log2(n*2));
  for (long long i = n, e = n * 2; i < e; ++i) {
    cin >> arr[i];
  }
  buildTree();
  long long q; cin >> q;
  long long t, x, y;
  long long val;
  while (q--) {
    cin >> t >> x >> y;
    if (t == 1) {
      cin >> val;
      updateinterval(x-1, y, val);
    } else
      cout << query(x-1, y) << endl;
  }

  return 0;
}
