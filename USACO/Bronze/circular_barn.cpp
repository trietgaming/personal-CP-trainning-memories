#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int rooms[1000];

int main() {

  freopen("cbarn.in", "r", stdin);
  freopen("cbarn.out", "w", stdout);

  int n; cin >> n;
  int cows = 0;

  for (int i = 0; i < n; ++i) {
    cin >> rooms[i];
    cows += rooms[i];
  }

  int res = INF;

  for (int i = 0; i < n; ++i) {
    int temp = 0, currentCows = cows - rooms[i];
    for (int j = i + 1; j < n; ++j) {
      temp += currentCows;
      currentCows -= rooms[j];
    }
    for (int j = 0; j < i; ++j) {
      temp += currentCows;
      currentCows -= rooms[j];
    }
    res = min(res, temp);
  }

  cout << res;

  return 0;
}
