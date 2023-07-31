#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "bai1";
const int INF = 1e9 + 7;
//const int MAXN =;
long long res = 0, n;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".inp").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n;

  ll x = n;
  for (ll alpha = 1; ; ++alpha) {
    x = 2*n-alpha*alpha+alpha;
    if (x % (2*alpha) != 0) continue;
    if (x < 0) {
      cerr << alpha;
      break;
    }
    x /= 2*alpha;
    ++res;
//    cerr << (ll) x << "\n";
  }

  cout << res;
//  cerr << res;

  return 0;
}


