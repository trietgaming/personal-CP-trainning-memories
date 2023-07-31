#include <bits/stdc++.h>

using namespace std;

const string FNAME = "wormsort";
const int MAXNM = 100001;

struct Edge {
  int to, w;
};

struct Hole {
  int a, b, w;
};

int n, m;
Hole holes[MAXNM];
int pos[MAXNM];
vector<Edge> hole_edges[MAXNM];
int visited[MAXNM];

void dfs(int cur, int min_w, int id) {
  visited[cur] = id;
  for (Edge adj: hole_edges[cur]) {
    if (visited[adj.to] || adj.w < min_w) continue;
    dfs(adj.to, min_w, id);
  }
}

bool can_sort_all_cows_with_hole_at_least(int width) {
  int id = 1;
  fill(visited, visited + n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    if (visited[i]) continue;
    dfs(i, width, id++);
  }
  for (int i = 1; i <= n; ++i) {
    if (pos[i] != i && visited[i] != visited[pos[i]]) return false;
  }
  return true;
}

int find_max_least_width_hole(int l, int r) {
  if (l == r) {
    if (can_sort_all_cows_with_hole_at_least(holes[l].w)) return holes[l].w;
    return -1;
  }
  int mid = l + (r - l + 1) / 2;
  if (can_sort_all_cows_with_hole_at_least(holes[mid].w)) return find_max_least_width_hole(mid, r);
  return find_max_least_width_hole(l, mid - 1);
}

bool cmp(const Hole &a, const Hole &b) {
  return a.w < b.w;
}

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n >> m;

  bool isSorted = true;
  for (int i = 1; i <= n; ++i) {
    cin >> pos[i];
    isSorted = isSorted && pos[i] == i;
  }

  if (isSorted) {
    cout << -1;
    return 0;
  }

  for (int i = 0; i < m; ++i) {
    Hole &h = holes[i];
    Edge a, b;
    cin >> h.a >> h.b >> h.w;

    a.w = h.w;
    b.w = h.w;
    a.to = h.b;
    b.to = h.a;

    hole_edges[h.a].push_back(a);
    hole_edges[h.b].push_back(b);
  }

  sort(holes, holes + m, cmp);

  cout << find_max_least_width_hole(0, m - 1);

  return 0;
}


