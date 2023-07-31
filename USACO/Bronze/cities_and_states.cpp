#include <bits/stdc++.h>

using namespace std;

const string FNAME = "citystate";

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n; cin >> n;
  int res = 0;

  unordered_map<string, unordered_map<string, int>> mp;

  string s1, s2;
  for (int i = 0; i < n; ++i) {
    cin >> s1 >> s2;
    string city = s1.substr(0, 2);
    if (s2 != city)
      res += mp[city][s2];
    mp[s2][city]++;
  }

  cout << res;

  return 0;
}


