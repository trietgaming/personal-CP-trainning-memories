#include <bits/stdc++.h>

using namespace std;

string names[8] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy","Sue"};
unordered_map<string, int> nameToInd;
unordered_map<int, string> indToName;
int perms[8];

vector<set<int>> nexts;

int main() {

  freopen("lineup.in", "r", stdin);
  freopen("lineup.out", "w", stdout);

  sort(names, names + 8);

  for (int i = 0; i < 8; ++i) {
    nameToInd[names[i]] = i;
    indToName[i] = names[i];
    perms[i] = i;
  }

  int n;
  cin >> n;

  string temp;
  for (int i = 0; i < n; ++i) {
    set<int> p;
    cin >> temp;
    p.insert(nameToInd[temp]);
    for (int j = 0; j < 4; ++j) cin >> temp;
    cin >> temp;
    p.insert(nameToInd[temp]);
    nexts.push_back(p);
  }

  do {

    int cur = 0;
    for (int i = 0; i < 7; ++i) {
      set<int> p;
      p.insert(perms[i]);
      p.insert(perms[i + 1]);
      for (auto ne: nexts) {
        if (p == ne) ++cur;
      }
    }
    if (cur == nexts.size()) break;

  } while (next_permutation(perms, perms + 8));

  for (int i = 0; i < 8; ++i) {
    cout << indToName[perms[i]] << endl;
  }

  return 0;
}
