#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define Point complex<ll>
#define Vector2 Point
#define x() real()
#define y() imag()

const string FNAME = "";
const int INF = 1e9 + 7;
//const int MAXN =;

ll cross_product(Vector2 &a, Vector2 &b) {
  return (ll) a.x() * b.y() - b.x() * a.y();
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int T;
  cin >> T;
  while (T--) {
    int x1, y1, x2, y2, x, y;
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
    Vector2 v1(x2-x1, y2-y1), v2(x-x1, y-y1);
    if (cross_product(v1, v2) == 0) cout << "TOUCH";
    else if (cross_product(v1, v2) > 0) cout << "LEFT";
    else cout << "RIGHT";
    cout << "\n";
  }

  return 0;
}


