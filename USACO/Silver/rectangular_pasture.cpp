#include <bits/stdc++.h>

using namespace std;

const string FNAME = "recpas";
const int MAXN = 2510;

struct Point {
  int x, y;
};

bool cmpByX(Point &a, Point &b) {
  return a.x < b.x;
}

bool cmpByY(Point &a, Point &b) {
  if (a.y == b.y) return a.x < b.x;
  return a.y < b.y;
}

long long recCount[MAXN][MAXN];
Point arr[MAXN];

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i].x >> arr[i].y;
  }

  sort(arr, arr + n, cmpByX);
  for (int i = 1; i <= n; ++i) {
    arr[i-1].x = i;
  }

  sort(arr, arr + n, cmpByY);
  for (int i = 1; i <= n; ++i) {
    arr[i-1].y = i;
  }

  for (int i = 0; i < n; ++i) recCount[arr[i].y][arr[i].x] = 1;

  for (int i = 1; i < MAXN; ++i) {
    for (int j = 1; j < MAXN; ++j) {
      recCount[i][j] = recCount[i][j] + recCount[i-1][j] + recCount[i][j-1] - recCount[i-1][j-1];
    }
  }

  long long res = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
        int u = arr[j].y, d = arr[i].y;
        int l = min(arr[j].x, arr[i].x), r = max(arr[j].x, arr[i].x);
//        cout << "(" << u.x << ";" << u.y << ")" << "(" << d.x << ";" << d.y << ")" << endl;
//        cout << "low: " << recCount[d.y][u.x] - recCount[d.y][d.x - 1] << endl;
//        cout << "high: " << recCount[MAXN-1][u.x] - recCount[u.y - 1][u.x] - recCount[MAXN-1][d.x-1] + recCount[u.y-1][d.x-1] << endl;
        res += (long long) (recCount[d][r] - recCount[d][l - 1]) * (recCount[MAXN-1][r] - recCount[u- 1][r] - recCount[MAXN-1][l-1] + recCount[u-1][l-1]);
    }
  }

  res += n + 1;
  cout << res;

  return 0;
}

