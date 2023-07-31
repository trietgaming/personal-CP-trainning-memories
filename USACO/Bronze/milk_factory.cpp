#include <bits/stdc++.h>

using namespace std;

const string FNAME = "factory";
const int MAXN = 100;

vector<int> edges[MAXN+1];
vector<bool> common(MAXN, true);

void dfs(int node, vector<bool> &visited) {
  visited[node] = true;
  for (int i = 0, s = edges[node].size(); i < s; ++i) {
    int adjacent = edges[node][i];
    if (visited[adjacent]) continue;
    dfs(adjacent, visited);
  }
}

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n; cin >> n;

  for (int i = 1; i < n; ++i) {
    int from, to;
    cin >> from >> to;
    edges[from].push_back(to);
  }

  for (int i = 1; i <= n; ++i) {
    vector<bool> visited(n + 1, false);
    dfs(i, visited);
    for (int j = 1; j <= n; ++j) {
      if (visited[j]) continue;
      common[j] = false;
    }
  }

  int res = -1;
  for (int i = 1; i <= n; ++i) {
    if (common[i]) {
      res = i;
      break;
    }
  }

  cout << res;

  return 0;
}


