#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "closing";
const int MAXNM = 3001;

int n, m;
vector<int> edges[MAXNM];
bool removed[MAXNM];
int visited[MAXNM];

void dfs(int id, int node, int &visit_count) {
  ++visit_count;
  visited[node] = id;
  for (int adj: edges[node]) {
    if (removed[adj] || visited[adj] == id) continue;
    dfs(id, adj, visit_count);
  }
}

bool is_fully_connected(int id) {
  int c = 0;
  for (int i = 1; i <= n; ++i) {
    if (removed[i]) continue;
    dfs(id, i, c);
    break;
  }
  return c == n - id;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  fill(visited, visited + MAXNM + 1, -1);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  for (int i = 0; i < n; ++i) {
    if (is_fully_connected(i)) cout << "YES";
    else cout << "NO";
    cout << "\n";
    int be_removed;
    cin >> be_removed;
    removed[be_removed] = true;
  }

  return 0;
}


