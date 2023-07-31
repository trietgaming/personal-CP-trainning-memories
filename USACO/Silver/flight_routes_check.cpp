#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "routecheck";
const int MAXN = 100001;

vector<int> directed[MAXN], reversed_directed[MAXN];
bool visited[MAXN], visited_reversed[MAXN];

void dfs(int city, bool v[], vector<int> graph[]) {
  v[city] = true;
  for (int adj: graph[city]) {
    if (v[adj]) continue;
    dfs(adj, v, graph);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;

    directed[a].push_back(b);
    reversed_directed[b].push_back(a);
  }

  dfs(1, visited, directed);
  dfs(1, visited_reversed, reversed_directed);

  for (int i = 2; i <= n; ++i) {
    if (!visited[i] || !visited_reversed[i]) {
      cout << "NO" << "\n";
      if (!visited[i]) cout << 1 << " " << i;
      else cout << i << " " << 1;
      return 0;
    }
  }

  cout << "YES";

  return 0;
}


