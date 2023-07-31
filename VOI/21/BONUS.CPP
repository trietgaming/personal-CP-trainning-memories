#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "BONUS";
const int INF = 1e9 + 7;
const int MAXN = 102;
const int MAXM = 100;
const int MAXPOINT = 1e5 + 1;

struct Card {
  int p;
  string tag;
};

Card arr[MAXN];
unordered_set<int> pairlucky[MAXPOINT];

ll dp[MAXN];

bool isPrefix(string &child, string &par) {
  for (int i = 0, e = child.length(); i < e; ++i) {
    if (child[i] != par[i]) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  #ifdef LIONELMESSI
  freopen((FNAME + ".inp").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);
  #endif

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i].tag >> arr[i].p;
    dp[i] = arr[i].p;
  }
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    pairlucky[a].insert(b);
    pairlucky[b].insert(a);
  }
  ll res= 0;

  if (n <= 100) {

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if ((arr[j].tag.length() < arr[i].tag.length() && isPrefix(arr[j].tag, arr[i].tag))
            || pairlucky[arr[i].p].count(arr[j].p)
            ) {
          dp[j] = max(dp[j], dp[i] + arr[j].p);
        }
      }
      res = max(res, dp[i]);
    }

  }

  cout << res;

  return 0;
}


