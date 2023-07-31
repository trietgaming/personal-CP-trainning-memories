#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Cow {
  int x, y;
  double radius;
};

const string FNAME = "moocast";
const int MAXN = 200;

int n;
Cow cows[MAXN];
vector<int> edges[MAXN];
bool visited[MAXN];

double euclid_distance(Cow &a, Cow &b) {
  return sqrt(pow(abs(a.x - b.x), 2) + pow(abs(a.y - b.y), 2));
}

bool is_reachable(Cow &a, Cow &b) {
  return a.radius >= euclid_distance(a, b);
}

void dfs(int node, int &component_size) {
  ++component_size;
  visited[node] = true;
  for (int adj: edges[node]) {
    if (visited[adj]) continue;
    dfs(adj, component_size);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> cows[i].x >> cows[i].y >> cows[i].radius;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      if (is_reachable(cows[i], cows[j]))
        edges[i].push_back(j);
    }
  }

  int res = 0;

  for (int i = 0; i < n; ++i) {
    fill(visited, visited + n, false);
    int component_size = 0;
    dfs(i, component_size);
    res = max(res, component_size);
  }

  cout << res;

  return 0;
}


