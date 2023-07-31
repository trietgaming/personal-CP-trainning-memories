#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define Point complex<long double>
#define x real()
#define y imag()

const string FNAME = "";
const int INF = 1e9 + 7;
const int MAXN = 200001;

Point points[MAXN];

bool cmp(Point &a, Point &b) {
  return atan2(a.y, a.x) < atan2(b.y, b.x);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int px, py;
    cin >> px >> py;
    points[i] = Point(px, py);
  }

  sort(points, points + n, cmp);

  for (int i = 0; i < n; ++i) {
    ll px = points[i].x;
    ll py = points[i].y;
    cout << px << " " << py << "\n";
  }

  return 0;
}


