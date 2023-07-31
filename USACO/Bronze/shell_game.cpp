#include <bits/stdc++.h>

using namespace std;

int currentPos[3] = {0, 1, 2}, currentScore[3];

int main() {

//  freopen("shell.in", "r", stdin);
//  freopen("shell.out", "w", stdout);

  int n; cin >> n;
  for (int i = 0, a, b, g; i < n; ++i) {
    cin >> a >> b >> g;
    swap(currentPos[--a], currentPos[--b]);
    ++currentScore[currentPos[g - 1]];
  }

  int maxScore = INT_MIN;

  for (int i = 0; i < n; ++i) {
    maxScore = max(maxScore, currentScore[i]);
  }

  cout << maxScore;

  return 0;
}
