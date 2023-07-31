#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using pres = pii;

const string FNAME = "game";
const ll INF = 1e18;
const int MAXMN = 5005;

struct Edge {
  ll from, to, w, id;
  Edge(ll f = 0, ll t = 0, ll weight = 0, ll i = -1): from(f), to(t), id(i), w(weight) {
    assert(i >= 0);
  };
};

bool visited_edge[MAXMN];

vector<Edge> edges[MAXMN];
pres dp[MAXMN][MAXMN];

void dfs(int node, Edge last_edge) {
  visited_edge[last_edge.id] = true;
  for (Edge adj: edges[node]) {
    if (visited_edge[adj.id]) continue;
    pres temp(min(adj.w, dp[last_edge.from][node].first), max(adj.w, dp[last_edge.from][node].second));

    if (dp[node][adj.to].first + dp[node][adj.to].second >= INF || temp.first + temp.second > dp[node][adj.to].first + dp[node][adj.to].second)
      dp[node][adj.to] = temp;
  }
  for (Edge adj: edges[node])
    if (!visited_edge[adj.id]) dfs(adj.to, adj);
    cout << last_edge.from << "->" << node << ": " << dp[last_edge.from][node].first << ", " << dp[last_edge.from][node].second << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".inp").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i <= n; ++i)
    fill(dp[i], dp[i] + n + 1, pres(INF, 0));

  for (int i = 1; i <= n; ++i) {
    ll a, b, w;
    cin >> a >> b >> w;
    edges[a].push_back(Edge(a, b, w, i));
    edges[b].push_back(Edge(b, a, w, i));

  }

  ll res = 0;

  for (int i = 1; i <= n; ++i) {
    fill(visited_edge, visited_edge + n + 1, false);
    dfs(i, Edge(0, 0, INF, 0));
    for (Edge adj: edges[i])
      if (dp[adj.to][i].first + dp[adj.to][i].second < INF)
        res = max(res, dp[adj.to][i].first + dp[adj.to][i].second);
  }

  cout << res;

  return 0;
}


