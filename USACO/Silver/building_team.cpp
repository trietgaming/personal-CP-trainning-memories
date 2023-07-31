#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "";
const int MAXN = 100001;

int n, m;

vector<int> edges[MAXN];
bool visited[MAXN], colored[MAXN];

void dfs(int cur, bool color, bool &valid) {
  visited[cur] = true;
  colored[cur] = color;

  for (int adj: edges[cur]) {
    if (visited[adj]) {
       if (colored[adj] == color) {
        valid = false;
        return;
       }
       continue;
    }
    dfs(adj, !color, valid);
    if (!valid) return;
  }
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
    edges[b].push_back(a);
  }

  bool valid = true;
  for (int i = 1; i <= n; ++i) {
    if (visited[i]) continue;
    dfs(i, true, valid);
  }

  if (!valid) cout << "IMPOSSIBLE";
  else for (int i = 1; i <= n; ++i) cout << colored[i] + 1 << " ";

  return 0;
}


