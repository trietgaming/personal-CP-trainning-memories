#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "";
const int INF = 1e9 + 7;
const int MAXN = 1001;

int succ[MAXN], res[MAXN];

void gen(int node) {
  int a = node, b = node;
  do {
    a = succ[a];
    b = succ[succ[b]];
  } while (a != b);

  a = node;
  while (a != b) {
    a = succ[a];
    b = succ[b];
  }

  b = a;
  res[node] = a;
  do {
    res[b] = b;
    b = succ[b];
  } while (a != b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> succ[i];
  }
  for (int i = 1; i <= n; ++i) {
    gen(i);
  }

  for (int i = 1; i <= n; ++i) {
    cout << res[i] << " ";
  }

  return 0;
}


