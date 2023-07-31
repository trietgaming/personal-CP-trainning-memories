#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "";
const int INF = 1e9 + 7;
const int MAXN = 2*1e5 + 1;

vector<int> st[4*MAXN];
int arr[MAXN];

void build(int id, int l, int r) {
  if (l == r) {
    st[id].clear();
    st[id].push_back(arr[l]);
    return;
  }
  int mid = (l + r) >> 1;
  build(id << 1, l, mid);
  build(id << 1 | 1, mid + 1, r);
  st[id].clear();
  st[id].resize(st[id << 1].size() + st[id << 1 | 1].size());
  merge(st[id << 1].begin(), st[id << 1].end(), st[id << 1 | 1].begin(), st[id << 1 | 1].end(), st[id].begin());
}

int count_num_greater(int id, int l, int r, int ql, int qr, int k) {
  if (l > qr || r < ql) return 0;
  if (l >= ql && r <= qr) {
    return distance(upper_bound(st[id].begin(), st[id].end(), k), st[id].end());
  }
  int mid = (l + r) >> 1;
  return count_num_greater(id << 1, l, mid, ql, qr, k) + count_num_greater(id << 1 | 1, mid + 1, r, ql, qr, k);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> arr[i];
    }
    build(1, 1, n);
    for (int i = 2; i <= n; ++i) {
      res += count_num_greater(1, 1, n, 1, i - 1, arr[i]);
    }

    cout << res << "\n";
  }

  return 0;
}


