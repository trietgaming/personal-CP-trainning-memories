#include <bits/stdc++.h>

using namespace std;

const string FNAME = "evolution";
const int MAXN = 25;

vector<string> features;
unordered_map<string, bool> appears[MAXN];

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int k; cin >> k;
    for (int j = 0; j < k; ++j) {
      string s;
      cin >> s;
      appears[i][s] = true;
      features.push_back(s);
    }
  }

  for (int i = 0, e = features.size(); i < e; ++i) {
    for (int j = i + 1; j < e; ++j) {
      bool hasInotJ = false, hasJnotI = false, hasBoth = false;
      for (int cow = 0; cow < n; ++cow) {
        bool thisHasI = appears[cow][features[i]], thisHasJ = appears[cow][features[j]];
        if (thisHasI && !thisHasJ) hasInotJ = true;
        if (thisHasJ && !thisHasI) hasJnotI = true;
        if (thisHasI && thisHasJ) hasBoth = true;
      }
      if (hasInotJ && hasJnotI && hasBoth) {
        cout << "no";
        return 0;
      }
    }
  }

  cout << "yes";

  return 0;
}

