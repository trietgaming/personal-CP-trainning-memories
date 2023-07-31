#include <bits/stdc++.h>

using namespace std;

const string FNAME = "hps";
const int MAXN = 100000;

int totalWin[256][MAXN + 1];
int iterateGesture[3] = {'H', 'P', 'S'};

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    char gesture;
    cin >> gesture;
    if (gesture == 'P') {
      ++totalWin['S'][i];
    } else if (gesture == 'S') {
      ++totalWin['H'][i];
    } else /*H*/ {
      ++totalWin['P'][i];
    }
    for (int g = 0; g < 3; ++g) {
      totalWin[iterateGesture[g]][i] += totalWin[iterateGesture[g]][i - 1];
    }
  }

  int res = 0;

  for (int sw = 1; sw <= n; ++sw) {
    for (int i = 0; i < 3; ++i) {
      for (int j = i + 1; j < 3; ++j) {
        int g1 = iterateGesture[i], g2 = iterateGesture[j];
        res = max(res, totalWin[g1][sw] + totalWin[g2][n] - totalWin[g2][sw]);
        res = max(res, totalWin[g2][sw] + totalWin[g1][n] - totalWin[g1][sw]);
      }
    }
  }

  cout << res;

  return 0;
}


