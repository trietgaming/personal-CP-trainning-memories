#include <bits/stdc++.h>

using namespace std;

const string FNAME = "div7";

vector<int> minIndMod7EqualTo(7, -1);

int main() {
  minIndMod7EqualTo[0] = 0;

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  int sum = 0, res = 0;
  for (int i = 1; i <= n; ++i) {
    int cow;
    cin >> cow;
    sum = (sum + cow) % 7;
    if (minIndMod7EqualTo[sum] == -1) minIndMod7EqualTo[sum] = i;
    res = max(res, i - minIndMod7EqualTo[sum]);
  }

  cout << res;

  return 0;
}

