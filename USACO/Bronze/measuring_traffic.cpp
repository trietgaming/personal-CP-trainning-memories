#include <bits/stdc++.h>

using namespace std;

const string NONE = "none", ONRAMP = "on", OFFRAMP = "off";
const int INF = 1e9;

struct range {
  int s;
  int e;
  string t;
};

range arr[100];

int main() {

  freopen("traffic.in", "r", stdin);
  freopen("traffic.out", "w", stdout);
  int n; cin >> n;

  for (int i = 0; i < n; ++i) {
    range &r = arr[i];
    cin >> r.t >> r.s >> r.e;
  }

  range res;
  res.s = -INF;
  res.e = INF;

  for (int i = n-1; i >= 0; --i) {
    if (arr[i].t == NONE) {
      res.s = max(res.s, arr[i].s);
      res.e = min(res.e, arr[i].e);
      continue;
    }
    if (arr[i].t == OFFRAMP) {
      res.s += arr[i].s;
      res.e += arr[i].e;
    }
    else {
      res.s -= arr[i].e;
      res.e -= arr[i].s;
      res.s = max(res.s, 0);
    }
    if (res.e < res.s) swap(res.e, res.s);
  }

  cout << min(res.s, res.e) << " " << max(res.e, res.s) << "\n";

  res.s = -INF;
  res.e = INF;

  for (int i = 0; i < n; ++i) {
    if (arr[i].t == NONE) {
      res.s = max(res.s, arr[i].s);
      res.e = min(res.e, arr[i].e);
      continue;
    }
    if (arr[i].t == ONRAMP) {
      res.s += arr[i].s;
      res.e += arr[i].e;
    }
    else {
      res.s -= arr[i].e;
      res.e -= arr[i].s;
      res.s = max(res.s, 0);
    }
    if (res.e < res.s) swap(res.e, res.s);
  }

  cout << min(res.s, res.e) << " " << max(res.e, res.s);

  return 0;
}
