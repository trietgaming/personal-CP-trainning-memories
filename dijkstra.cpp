#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "dijkstra";
const ll INF = 1e18;
const int MAXN = 102;

vector<pii> edges[MAXN];
vector<int> shortest_path[MAXN][MAXN];
ll shortest_path_length[MAXN][MAXN];
int trace[MAXN];
int n, m;

void dijkstra(int u) {
  fill(shortest_path_length[u], shortest_path_length[u] + n + 1, INF);
  fill(trace, trace + n + 1, - 1);
  priority_queue<pii, vector<pii>, greater<pii>> q;
  shortest_path_length[u][u] = 0;
  q.push({0, u});
  while (q.size()) {
    int node = q.top().second;
    int d = q.top().first;
    q.pop();

    if (d != shortest_path_length[u][node]) continue;
    for (auto adj: edges[node]) {
      if (d + adj.second < shortest_path_length[u][adj.first]) {
        shortest_path_length[u][adj.first] = d + adj.second;
        trace[adj.first] = node;
        q.push({d + adj.second, adj.first});
      }
    }
  }
  for (int v = 1; v <= n; ++v) {
    shortest_path[u][v].push_back(v);
    int par = trace[v];
    while (par != -1) {
      shortest_path[u][v].push_back(par);
      par = trace[par];
    }
    reverse(shortest_path[u][v].begin(), shortest_path[u][v].end());
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n >> m;
  int K;
  cin >> K;
  for (int i = 0; i < m; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    edges[a].push_back({b, w});
    edges[b].push_back({a, w});
  }

  while (K--) {
    int t, u, v;
    cin >> t >> u >> v;
    if (shortest_path[u][v].empty()) {
      dijkstra(u);
    }
    if (t) {
      cout << shortest_path[u][v].size() << " ";
      for (int p: shortest_path[u][v]) {
        cout << p << " ";
      }
    }
    else {
      cout << shortest_path_length[u][v];
    }
      cout << "\n";
  }

  return 0;
}


