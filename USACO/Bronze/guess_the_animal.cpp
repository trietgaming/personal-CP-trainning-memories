#include <bits/stdc++.h>

using namespace std;

unordered_map<string, bool> animals[100];

int main() {

  freopen("guess.in", "r", stdin);
  freopen("guess.out", "w", stdout);

  int n; cin >> n;

  set<string> characteristics;

  for (int i = 0; i < n; ++i) {
    string animal;
    cin >> animal;
    int chs;
    cin >> chs;
    for (int j = 0; j < chs; ++j) {
      string ch;
      cin >> ch;
      animals[i][ch] = true;
    }
  }

  int res = 0;

  for (int i = 0; i < n; ++i) {
    auto &animal = animals[i];
    int current = 0;
    for (int j = i + 1; j < n; ++j) {
      int temp = 0;
      for (auto ch: animals[j]) {
        if (animal[ch.first]) ++temp;
      }
      current = max(temp, current);
    }
    if (animal.size() > current) ++current;
    res = max(res, current);
  }

  cout << res;

  return 0;
}
