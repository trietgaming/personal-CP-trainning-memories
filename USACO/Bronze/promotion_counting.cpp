#include <bits/stdc++.h>

using namespace std;

const string FILENAME = "promote";

int contest[5][2];
int res[5];

int main() {


  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 2; ++j) {
      cin >> contest[i][j];
    }
  }
  for (int i = 3; i >= 0; --i) {
    res[i] = contest[i][1]- contest[i][0];
    contest[i-1][0]-= res[i];
  }

  for (int i = 1; i < 4; ++i) cout << res[i] << "\n";

  return 0;
}
