#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "movie";
const int MAXN = 200000;

struct Movie {
  int s, e;
  Movie() {};
  Movie(int st, int en) {
    s = st;
    e = en;
  }
};

bool cmp(const Movie &a, const Movie &b) {
  if (a.e == b.e) return a.s < b.s;
  return a.e < b.e;
}

Movie movies[MAXN + 1];
int zeroArr[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int movieNum, memberNum;

  cin >> movieNum >> memberNum;

  multiset<int> members(zeroArr, zeroArr + memberNum);

  for (int i = 0; i < movieNum; ++i) {
    cin >> movies[i].s >> movies[i].e;
  }

  sort(movies, movies + movieNum, cmp);

  int res = movieNum;

  for (int i = 0; i < movieNum; ++i) {
    auto whoWatchThis = members.upper_bound(movies[i].s);
    if (whoWatchThis == members.begin()) {
      --res;
      continue;
    }
    --whoWatchThis;
    members.erase(whoWatchThis);
    members.insert(movies[i].e);
  }

  cout << res;

  return 0;
}


