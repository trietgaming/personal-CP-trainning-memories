#include <bits/stdc++.h>

using namespace std;

const string FNAME = "div2019";
const int MAXN = 200001;

int suffix[MAXN + 1];
long long countMod[2019];

int main() {

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  string s;
  cin >> s;

  int base = 1;
  countMod[0] = 1;

  for (int i = s.size() - 1; i >= 0; --i) {
    int a = s[i] - '0';

    suffix[i] = (a * base + suffix[i+1] ) % 2019;
    base = (base * 10) % 2019;
    ++countMod[suffix[i]];
  }

  long long res = 0;
  for (int i = 0; i <= 2018; ++i) {
    int mods = countMod[i];
    res += mods*(mods-1)/2;
  }

  cout << res;

  return 0;
}


