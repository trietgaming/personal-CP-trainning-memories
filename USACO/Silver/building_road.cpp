#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "roadbuild";
const int MAXN = 100001;

int n, m;
vector<int> roads[MAXN];
bool visited[MAXN];

void dfs(int city) {
  visited[roads[city][i]] = true;
  for (int i = 0, s = roads[city].size(); i < s; ++i) {
    if (visited[roads[city][i]]) continue;
    dfs(roads[city][i]);
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

    roads[a].push_back(b);
    roads[b].push_back(a);
  }

  vector<int> res;
  for (int i = 1; i <= n; ++i) {
    if (visited[i]) continue;
    res.push_back(i);
    dfs(i);
  }

  cout << res.size() - 1 << "\n";

  for (int i = 1; i < res.size(); ++i) {
    cout << res[i - 1] << " " << res[i] << "\n";
  }

  return 0;
}


