#include <bits/stdc++.h>

using namespace std;

int main() {

  freopen("word.in", "r", stdin);
  freopen("word.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  string s;
  vector<string> v;
  while (n--) {
    cin >> s;
    v.push_back(s);
  };
  s.resize(10000);
  v.push_back(s);
  int remain = k;
  for (int i = 0; i < v.size() - 1; ++i) {
    cout << v[i];
    remain -= v[i].length();
    if (v[i + 1].length() <= remain) {
      cout << " ";
    }
    else {
      remain = k;
      cout << "\n";
    }
  }
  return 0;
}
