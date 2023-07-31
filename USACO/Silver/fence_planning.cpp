#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "fenceplan";
const int MAXNM = 100001;

struct Cow {
  int x, y;
};

int n, m;
Cow cows[MAXNM];
vector<int> edges[MAXNM];
bool visited[MAXNM];

void dfs(int cow, vector<int> &network) {
  visited[cow] = true;
  network.push_back(cow);
  for (int adj: edges[cow]) {
    if (visited[adj]) continue;
    dfs(adj, network);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> cows[i].x >> cows[i].y;
  }
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  vector<vector<int>> networks;

  for (int i = 1; i <= n; ++i) {
    if (visited[i]) continue;
    networks.resize(networks.size() + 1);
    dfs(i, networks.back());
  }

  int res = INT_MAX;

  for (vector<int> &network: networks) {
    int left_most = 1e9;
    int right_most = -1;
    int top_most = -1;
    int bottom_most = 1e9;
    for (int cow_index: network) {
      Cow &cow = cows[cow_index];
      left_most = min(left_most, cow.x);
      right_most = max(right_most, cow.x);
      top_most = max(top_most, cow.y);
      bottom_most = min(bottom_most, cow.y);
    }
    res = min(res, (right_most - left_most) * 2 + (top_most - bottom_most) * 2);
  }

  cout << res;

  return 0;
}


