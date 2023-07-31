#include <bits/stdc++.h>

using namespace std;

const string FNAME = "planting";
const int MAXN = 100000;

vector<int> edges[MAXN+1];

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n; cin >> n;

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  unsigned int res = 0;
  for (int i = 1; i <= n; ++i) {
    res = max(res, static_cast<unsigned int>(edges[i].size()));
  }

  cout << res + 1;

  return 0;
}


