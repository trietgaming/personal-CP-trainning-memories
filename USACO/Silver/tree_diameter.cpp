#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "diameter";
const int MAXN = 2*1e5 + 1;

vector<int> edges[MAXN];

pair<int, int> find_farthest_node(int node, int prev = -1) {
  pair<int, int> res(0, node);
  for (int adj: edges[node]) {
    if (adj == prev) continue;
    pair<int, int> temp = find_farthest_node(adj, node);
    temp.first++;
    res = max(res, temp);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;

    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  cout << find_farthest_node(find_farthest_node(1).second).first;

  return 0;
}


