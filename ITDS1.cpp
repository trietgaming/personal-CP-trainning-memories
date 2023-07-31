#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

int n;
long long tree[MAXN << 1];

void update(int i, long long v) {
  for(tree[i += n] = v; i > 1; i >>=1) {
    tree[i >> 1] = min(tree[i], tree[i^1]);
  }
}

long long query(int l, int r, long long k) {
  long long res = LLONG_MAX;
  for (l += n, r += n; l < r; l >>= 1, r >>=1) {
    if (l&1 && tree[l++] >= k) res = min(res, tree[l-1]);
    if (r&1 && tree[--r] >= k) res = min(res, tree[r]);

  }
  return res == LLONG_MAX? -1: res;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  int m;
  cin >> n >> m;
  for (int i = n, e = n << 1; i < e; ++i) {
    cin >> tree[i];
  }

  for (int i = n-1; i > 0; --i) {
    tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
  }

  int t, x, y;
  long long k;
  while (m--) {
    cin >> t >> x >> y;
    if (t == 1) {
      update(x - 1, y);
      continue;
    }
    cin >> k;
    cout << query(x - 1, y, k) << endl;
  }

  return 0;
}
