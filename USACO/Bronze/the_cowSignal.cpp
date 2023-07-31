#include <bits/stdc++.h>

using namespace std;

int main() {

  freopen("cowsignal.in", "r", stdin);
  freopen("cowsignal.out", "w", stdout);

  int m, n, k;
  cin >> m >> n >> k;

  vector<vector<char> > v;

  for (int i = 0; i < m; ++i) {
    string signal; cin >> signal;
    string s;
    for (int j = 0; j < n; ++j) {
      for (int l = 0; l < k; ++l) {
        s += signal[j];
      }
    }
    for (int j = 0; j < k; ++j) {
      cout << s << "\n";
    }
  }


  return 0;
}
