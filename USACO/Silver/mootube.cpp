#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "mootube";
const int MAXN = 5001;

struct Edge {
  int to, relevance;
  Edge(int t = -1, int r = -1) {
    to = t;
    relevance = r;
  }
};

vector<Edge> edges[MAXN];

int count_suggest(int cur, int prev, int at_least) {
  int res = 0;
  for (Edge &e: edges[cur]) {
    if (e.to != prev && e.relevance >= at_least)
      res += count_suggest(e.to, cur, at_least) + 1;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, q;
  cin >> n >> q;
  for (int i = 1; i < n; ++i) {
    int a, b, r;
    cin >> a >> b >> r;
    edges[a].push_back({b, r});
    edges[b].push_back({a, r});
  }

  while (q--) {
    int k, v;
    cin >> k >> v;
    cout << count_suggest(v, -1, k) << "\n";
  }

  return 0;
}


