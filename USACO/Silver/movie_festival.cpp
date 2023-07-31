#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//const string FNAME = "";
const int MAXN = 200000;

struct Movie {
  int s, e;
};

bool cmp(const Movie &a, const Movie &b) {
  return a.e < b.e;
}

Movie movies[MAXN + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> movies[i].s >> movies[i].e;
  }

  sort(movies + 1, movies + n + 1, cmp);

  int res = 0, cur = 0;
  for (int i = 1; i <= n; ++i) {
    if (movies[i].s >= cur) {
      ++res;
      cur = movies[i].e;
    }
  }

  cout << res;

  return 0;
}

