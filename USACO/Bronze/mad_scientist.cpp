#include <bits/stdc++.h>

using namespace std;

const string FNAME = "breedflip";

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);
  int n; cin >> n;
  string a, b;
  cin >> a >> b;

  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      int j = i + 1;
      while (j < n && a[j] != b[j]) {
        ++j;
      }
      ++res;
      i = j;
    }
  }

  cout << res;

  return 0;
}


