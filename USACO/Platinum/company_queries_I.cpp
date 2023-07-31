#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "";
const int INF = 1e9 + 7;
const int MAXN = 2*1e5 + 1;
const int MAXPOW = 18;

int lift[MAXPOW+1][MAXN];

int k_th_ancestor(int node, int k) {
  for (int i = 0; i <= MAXPOW; ++i) {
    if ((k >> i) & 1) node = lift[i][node];
  }
  return node ?: -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, q;
  cin >> n >> q;

  for (int i = 2; i <= n; ++i) {
    cin >> lift[0][i];
  }

  for (int p = 1; p <= MAXPOW; ++p) {
    for (int i = 1; i <= n; ++i) {
      lift[p][i] = lift[p-1][lift[p-1][i]];
    }
  }

  while (q--) {
    int node, k;
    cin >> node >> k;
    cout << k_th_ancestor(node, k) << "\n";
  }

  return 0;
}


