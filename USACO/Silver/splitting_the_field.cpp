#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "split";
const int MAXN = 50000;

struct Cow {
  int x, y;
};

Cow cows[MAXN+1];
bool cmpByX(const Cow &a, const Cow &b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}

bool cmpByY(const Cow &a, const Cow &b) {
  if (a.y == b.y) return a.x < b.x;
  return a.y < b.y;
}

ll calculateArea(int l, int b, int r, int t) {
  return (ll) abs(t - b) * abs(r - l);
}

int leftMosts[MAXN+1], rightMosts[MAXN+1], bottomMosts[MAXN+1], topMosts[MAXN+1];

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> cows[i].x >> cows[i].y;
  }

  sort(cows, cows + n, cmpByX);

  leftMosts[n] = INT_MAX;
  rightMosts[n] = INT_MIN;
  bottomMosts[n] = INT_MAX;
  topMosts[n] = INT_MIN;

  for (int i = n-1; i >= 0; --i) {
    leftMosts[i] = min(leftMosts[i+1], cows[i].x);
    rightMosts[i] = max(rightMosts[i+1], cows[i].x);
    bottomMosts[i] = min(bottomMosts[i+1], cows[i].y);
    topMosts[i] = max(topMosts[i+1], cows[i].y);
  }
  ll areaOfOneRectangle = calculateArea(leftMosts[0], bottomMosts[0], rightMosts[0], topMosts[0]);

  int leftMost = cows[0].x;
  int rightMost = cows[0].x;
  int bottomMost = cows[0].y;
  int topMost = cows[0].y;

  ll result = 0;
  for (int i = 1; i < n; ++i) {
    ll diffAreaOfTwoRectangle = areaOfOneRectangle - calculateArea(leftMost, bottomMost, rightMost, topMost) - calculateArea(leftMosts[i], bottomMosts[i], rightMosts[i], topMosts[i]);
//    cout << leftMost << " " << bottomMost << "; " << rightMost << " " << topMost << " && " << leftMosts[i] << " " << bottomMosts[i] << "; " << rightMosts[i] << " " << topMosts[i] << endl;
//    cout << calculateArea(leftMost, bottomMost, rightMost, topMost) << " " << calculateArea(leftMosts[i], bottomMosts[i], rightMosts[i], topMosts[i]) << " " << diffAreaOfTwoRectangle << endl;
    result = max(result, diffAreaOfTwoRectangle);
    rightMost = cows[i].x;
    bottomMost = min(bottomMost, cows[i].y);
    topMost = max(topMost, cows[i].y);
  }


  sort(cows, cows + n, cmpByY);

  for (int i = n-1; i >= 0; --i) {
    leftMosts[i] = min(leftMosts[i+1], cows[i].x);
    rightMosts[i] = max(rightMosts[i+1], cows[i].x);
    bottomMosts[i] = min(bottomMosts[i+1], cows[i].y);
    topMosts[i] = max(topMosts[i+1], cows[i].y);
  }

  leftMost = cows[0].x;
  rightMost = cows[0].x;
  bottomMost = cows[0].y;
  topMost = cows[0].y;

  for (int i = 0; i < n; ++i) {
    ll diffAreaOfTwoRectangle = areaOfOneRectangle - calculateArea(leftMost, bottomMost, rightMost, topMost) - calculateArea(leftMosts[i], bottomMosts[i], rightMosts[i], topMosts[i]);
//    cout << leftMost << " " << bottomMost << "; " << rightMost << " " << topMost << " && " << leftMosts[i] << " " << bottomMosts[i] << "; " << rightMosts[i] << " " << topMosts[i] << endl;
//    cout << calculateArea(leftMost, bottomMost, rightMost, topMost) << " " << calculateArea(leftMosts[i], bottomMosts[i], rightMosts[i], topMosts[i]) << " " << diffAreaOfTwoRectangle << endl;
    result = max(result, diffAreaOfTwoRectangle);
    topMost = cows[i].y;
    leftMost = min(leftMost, cows[i].x);
    rightMost = max(rightMost, cows[i].x);
  }

  cout << result;

  return 0;
}


