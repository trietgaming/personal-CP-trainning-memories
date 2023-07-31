#include <bits/stdc++.h>

using namespace std;

int counter[256], localCounter[256][2];

int main() {

  freopen("blocks.in", "r", stdin);
  freopen("blocks.out", "w", stdout);

  int n; cin >> n;

  for (int i = 0; i < n; ++i) {
    string s1, s2;
    cin >> s1 >> s2;
    for (int j = 0; j < s1.length(); ++j) {
      ++localCounter[s1[j]][0];
    }
    for (int j = 0; j < s2.length(); ++j) {
      ++localCounter[s2[j]][1];
    }
    for (int j = 'a'; j <= 'z'; ++j) {
      counter[j] += max(localCounter[j][0], localCounter[j][1]);
      localCounter[j][0] = localCounter[j][1] = 0;
    }
  }

  for (int i = 'a'; i <= 'z'; ++i) {
    cout << counter[i] << "\n";
  }

  return 0;
}
