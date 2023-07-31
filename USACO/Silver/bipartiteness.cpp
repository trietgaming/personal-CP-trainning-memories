#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "";
const int MAXN = 100001;

vector<int> edges[MAXN];
bool visited[MAXN], colored[MAXN];

void color(int cur, bool clr) {
  visited[cur] = true;
  colored[cur] = clr;
  for (int adj: edges[cur]) {
    if (visited[adj]) continue;
    color(adj, !clr);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  ll n;
  cin >> n;

  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;

    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  color(1, true);
  ll c1 = 0, c2 = 0;

  for (int i = 1; i <= n; ++i) {
    if (colored[i]) ++c1;
    else ++c2;
  }

  cout << c1 * c2 - (n - 1);

  return 0;
}


