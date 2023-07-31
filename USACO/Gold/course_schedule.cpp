#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "";
const int MAXN = 1e5 + 1;

int n, m, order[MAXN];
vector<int> topo, edges[MAXN];
bool visited[MAXN];

void dfs(int node) {
  visited[node] = true;
  for (int adj: edges[node]) {
    if (visited[adj]) continue;
    dfs(adj);
  }
  topo.push_back(node);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
  }

  for (int i = 1; i <= n; ++i) {
    if (!visited[i])
      dfs(i);
  }
  for (int i = topo.size() - 1; i >= 0; --i) {
    order[topo[i]] = topo.size() - i - 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int adj: edges[i]) {
      if (order[adj] < order[i]) {
        cout << "IMPOSSIBLE";
        return 0;
      }
    }
  }
  for (int i = topo.size() - 1; i >= 0; --i) {
    cout << topo[i] << " ";
  }

  return 0;
}


