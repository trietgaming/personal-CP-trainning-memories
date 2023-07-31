#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "helpcross";
const int MAXN = 20000;

struct Cow {
  int s, e;
};

multiset<int> chickens;
Cow cows[MAXN];

bool cmp(const Cow &a, const Cow &b) {
  if (a.e == b.e) return a.s < b.s;
  return a.e < b.e;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int chickenNum, cowNum;
  cin >> chickenNum >> cowNum;

  for (int i = 0, c; i < chickenNum; ++i) {
    cin >> c;
    chickens.insert(c);
  }

  for (int i = 0; i < cowNum; ++i) {
    cin >> cows[i].s >> cows[i].e;
  }

  sort(cows, cows + cowNum, cmp);

  int res = 0;
  for (int i = 0; i < cowNum; ++i) {
    auto chicken = chickens.lower_bound(cows[i].s);
    if (chicken != chickens.end() && *chicken <= cows[i].e) {
      chickens.erase(chicken);
      ++res;
    }
  }

  cout << res;

  return 0;
}


