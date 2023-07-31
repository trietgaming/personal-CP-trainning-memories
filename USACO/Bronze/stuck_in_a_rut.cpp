#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = LLONG_MAX;
const int MAXN = 50;

struct Cow {
  int id;
  char dir;
  ll x;
  ll y;
  ll lim;
};

Cow arr[MAXN];
vector<ll> res(MAXN, INF);

bool sortByX(const Cow &a, const Cow &b) {
  return a.x < b.x;
}

bool sortByY(const Cow &a, const Cow &b) {
  return a.y < b.y;
}


int main() {

  vector<Cow> eY, nX;

  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i].dir >> arr[i].x >> arr[i].y;
    arr[i].id = i;
    arr[i].lim = INF;
    if (arr[i].dir == 'E') {
      eY.push_back(arr[i]);
    }
    else {
      nX.push_back(arr[i]);
    }
  }

  sort(eY.begin(), eY.end(), sortByY);
  sort(nX.begin(), nX.end(), sortByX);

  for (auto eCow: eY) {
    for (int j = 0; j < nX.size() && res[eCow.id] == INF; ++j) {
      Cow &nCow = nX[j];
      if (res[nCow.id] != INF) continue;
      if (eCow.lim < nCow.x|| nCow.x < eCow.x) continue;
      if (nCow.lim < eCow.y || nCow.y > eCow.y) continue;
      ll xDis = nCow.x - eCow.x, yDis = eCow.y - nCow.y;
      if (xDis == yDis) continue;
      if (xDis > yDis) {
        eCow.lim = nCow.x;
        res[eCow.id] = xDis;
        continue;
      }
      nCow.lim = eCow.y;
      res[nCow.id] = yDis;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (res[i] == INF) cout << "Infinity" << "\n";
    else cout << res[i] << "\n";
  }

  return 0;
}
