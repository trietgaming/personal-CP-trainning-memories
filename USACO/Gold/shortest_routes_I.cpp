#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

const string FNAME = "dijktra";
const ll INF = LLONG_MAX;
const int MAXN = 1e5 + 1;

vector<pii> edges[MAXN];
bool proceeded[MAXN];
ll shortest_from_1[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  fill(shortest_from_1, shortest_from_1 + MAXN, INF);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    ll a, b;
    ll w;
    cin >> a >> b >> w;

    edges[a].push_back({b, w});
  }

  priority_queue<pii, vector<pii>, greater<pii>> q;
  q.push({1, 0});
  shortest_from_1[1] = 0;

  while (!q.empty()) {
    pii top = q.top();
    q.pop();
    if (proceeded[top.first]) continue;
    proceeded[top.first] = true;
    for (pii adj: edges[top.first]) {
      ll w = shortest_from_1[top.first] + adj.second;
      if (w < shortest_from_1[adj.first]) {
        q.push({adj.first, shortest_from_1[adj.first] = w});
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << shortest_from_1[i] << " ";
  }

  return 0;
}
