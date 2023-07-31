#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "bfs";
const int MAXN = 1e5 + 1;

vector<int> edges[MAXN];
bool visited[MAXN];
int parent[MAXN];

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

    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  queue<int> q;
  visited[1] = true;
  parent[1] = 0;
  q.push(1);
  while (!q.empty()) {
    int f = q.front();
    q.pop();

    for (int adj: edges[f]) {
      if (visited[adj]) continue;
      visited[adj] = true;
      parent[adj] = f;
      q.push(adj);
    }
  }

  stack<int> res;
  int p = n;
  while (p) {
    res.push(p);
    p = parent[p];
  }
  if (res.top() != 1) cout << "IMPOSSIBLE";
  else {
    cout << res.size() << "\n";
    while (res.size()) {
      cout << res.top() << " ";
      res.pop();
    }
  }

  return 0;
}


