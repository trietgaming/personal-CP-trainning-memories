#include <bits/stdc++.h>

using namespace std;

int main() {

  freopen("censor.in", "r", stdin);
  freopen("censor.out", "w", stdout);

  string s, t;
  cin >> s >> t;

  string res = s.substr(0, t.length() - 1);
  for (int i = t.length() - 1; i < s.length(); ++i) {
    res += s[i];
    if (res.length() >= t.length() && res.substr(res.length() - t.length(), t.length()) == t) {
      res.resize(res.length() - t.length());
    }
  }

  cout << res;

  return 0;
}
