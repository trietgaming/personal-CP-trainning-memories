#include <bits/stdc++.h>

using namespace std;

const string FNAME = "emop";

int evens = 0, odds = 0;

int main() {

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n; cin >> n;

  for (int i = 0; i < n; ++i) {
    int temp;
    cin >> temp;
    if (temp & 1) ++odds;
    else ++evens;
  }

  int turn = 0, res = 0;
  while (evens || odds) {
    if (turn++ & 1) {
      if (odds) {
        --odds;
        ++res;
      } else {
        break;
      }
    } else {
      if (evens) {
        --evens;
        ++res;
      }
      else if (odds >= 2) {
        odds -= 2;
        ++res;
      }
      else if (odds == 1) {
        --res;
        --odds;
      }
    }
  }

  cout << res;

  return 0;
}

