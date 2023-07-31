#include <bits/stdc++.h>

using namespace std;

int n;
string s;
bool took[8];
set<string> res;

void generatePermutations(string str) {
  if (str.length() == n) {
    res.insert(str);
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (!took[i]) {
      took[i] = true;
      generatePermutations(str + s[i]);
      took[i] = false;
    }
  }
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s;
  n = s.length();

  generatePermutations("");

  cout << res.size() << endl;
  for (const string &str: res) cout << str << endl;

  return 0;
}
