#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const string FNAME = "BONUS";
const int INF = 1e9 + 7;
const int MAXN = 505;
const int MAXK = 1e5+1;
const int MAXP = 5 + 1;

ll n, k, r, p;

struct Point {
  int x, y;
  Point (int a = 0, int b = 0): x(a), y(b) {};
  bool operator < (Point b) {
    if (x == b.x) return y < b.y;
    return x < b.x;
  }
};

ll arr[MAXN][MAXN];

ll prefix_sum[MAXN][MAXN];

ll get_sum(Point tl, Point br) {
  return prefix_sum[br.y][br.x] - prefix_sum[br.y][tl.x - 1] - prefix_sum[tl.y - 1][br.x] + prefix_sum[tl.y - 1][tl.x - 1];
}

struct Rectangle {
  Point tl, br;
};
Rectangle recs[MAXK][MAXP];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".inp").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n >> k >> r >> p;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> arr[i][j];
      prefix_sum[i][j] = arr[i][j] + prefix_sum[i-1][j] + prefix_sum[i][j-1] - prefix_sum[i - 1][j - 1];
    }
  }

  for (int s = 0; s < k; ++s) {
    for (int i = 0; i < p; ++i) {
      cin >> recs[s][i].tl.x >> recs[s][i].tl.y;
      recs[s][i].br.x = recs[s][i].tl.x + r - 1;
      recs[s][i].br.y = recs[s][i].tl.y + r - 1;
    }
  }

  ll res = 0;
  for (int i = 0; i < k; ++i) {
    ll area = 0;
    for (int j = 0; j < p; ++j) {
      area += get_sum(recs[i][j].tl, recs[i][j].br);
      for (int l = j + 1; l < p; ++l) {
        Rectangle rec1 = recs[i][j], rec2 = recs[i][l];
        Point bl_1(rec1.tl.x, rec1.br.y), tr_1(rec1.br.x, rec1.tl.y);
        Point bl_2(rec2.tl.x, rec2.br.y), tr_2(rec2.br.x, rec2.tl.y);
        if (bl_1.x >= rec2.tl.x && rec1.br.y >= rec2.tl.y && rec1.br.x <= rec2.br.x && rec1.br.y <= rec2.br.y) {
          area -= get_sum(rec2.tl, rec1.br);
          continue;
        }
        if (bl_2.x >= rec1.tl.x && rec2.br.y >= rec1.tl.y && rec2.br.x <= rec1.br.x && rec2.br.y <= rec1.br.y) {
          area -= get_sum(rec1.tl, rec2.br);
          continue;
        }
        if (rec1.tl.x <= rec2.br.x && rec1.tl.y >= rec2.tl.y && rec1.br.x >= rec2.br.x && rec1.br.y >= rec2.br.y) {
          area -= get_sum(rec1.tl, rec2.br);
          continue;
        }
        if (rec2.tl.x <= rec1.br.x && rec2.tl.y >= rec1.tl.y && rec2.br.x >= rec1.br.x && rec2.br.y >= rec1.br.y) {
          area -= get_sum(rec2.tl, rec1.br);
          continue;
        }
        if (rec2.tl.x <= rec1.br.x && rec2.tl.x >= rec1.tl.x && rec2.tl.y <= rec1.br.y && rec2.tl.y >= rec1.tl.y) {
          area -= get_sum(rec2.tl, rec1.br);
          continue;
        }
        if (rec1.tl.x <= rec2.br.x && rec1.tl.x >= rec2.tl.x && rec1.tl.y <= rec2.br.y && rec1.tl.y >= rec2.tl.y) {
          area -= get_sum(rec1.tl, rec2.br);
          continue;
        }
        if (bl_1.x <= rec2.br.x && bl_1.y >= rec2.tl.y && bl_1.x >= rec2.tl.x && bl_1.y <= rec2.br.y) {
          area -= get_sum(Point(bl_1.x, rec2.tl.y), Point(rec2.tl.x, bl_1.y));
          continue;
        }
        if (bl_2.x <= rec1.br.x && bl_2.y >= rec1.tl.y && bl_2.x >= rec1.tl.x && bl_2.y <= rec1.br.y) {
          area -= get_sum(Point(bl_2.x, rec1.tl.y), Point(rec1.tl.x, bl_2.y));
          continue;
        }
      }
    }
    res = max(res, area);
  }

  cout << res;
  cerr << res;

  return 0;
}


