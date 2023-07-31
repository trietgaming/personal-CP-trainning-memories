#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "";
const int INF = 1e9 + 7;
const int MAXN = 10 + 1;

int kth[MAXN], res[3001];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;
  string str;
  cin >> str;
  for (int i = 0; i < n; ++i) {
    cin >> kth[i];
  }

  for (int len = 1, e = str.length() / 2; len <= e; ++len) {
    for (int i = 0; i + len*2 - 1< str.length(); ++i) {\
      int diff = 0;
      for (int j = i; j < i+len; ++j) {
        if (str[j] != str[j + len]) ++diff;
      }
      res[diff] = max(res[diff], len);
    }
  }

  for (int i = 0; i <= 10; ++i) {
    for (int j = 0; j < i; ++j) {
      res[i] = max(res[i], res[j]);
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << res[kth[i]] << "\n";
  }

  return 0;
}
