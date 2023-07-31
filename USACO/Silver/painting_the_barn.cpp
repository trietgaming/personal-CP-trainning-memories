#include <bits/stdc++.h>

using namespace std;

const string FNAME = "paintbarn";
long long plane[1001][1001], events[1001][1001];

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  long long n, k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    for (int y = y1; y < y2; ++y) {
      ++events[y][x1];
      --events[y][x2];
    }
  }

  for (int y = 0; y <= 1000; ++y) {
    long long cur = 0;
    for (int x = 0; x <= 1000; ++x) {
      plane[y][x] = (cur += events[y][x]);
    }
  }

  long long res = 0;

  for (int y = 0; y <= 1000; ++y) {
    for (int x = 0; x <= 1000; ++x) {
      res += (plane[y][x] == k);
    }
  }

  cout << res;

  return 0;
}


