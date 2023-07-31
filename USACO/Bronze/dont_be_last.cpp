#include <bits/stdc++.h>

using namespace std;

const string FNAME = "notlast";

unordered_map<string, int> cows({
                                  {
                                    "Bessie", 0
                                  },
                                  {
                                    "Elsie", 0
                                  },
                                  {
                                    "Daisy", 0
                                  },
                                  {
                                    "Gertie", 0
                                  },
                                  {
                                    "Annabelle", 0
                                  },
                                  {
                                     "Maggie", 0
                                  },
                                  {
                                    "Henrietta", 0
                                  }
                                });

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n; cin >> n;

  for (int i = 0, temp; i < n; ++i) {
    string s;
    cin >> s >> temp;
    cows[s]+=temp;
  }

  int m = INT_MAX;
  for (auto i: cows) {
    if (i.second < m) m = i.second;
  }
  int m2 = INT_MAX;
  vector<string> res;
  for (auto i: cows) {
    if (i.second < m2 && i.second > m) {
      m2 = i.second;
      res.clear();
      res.push_back(i.first);
    } else if (i.second == m2) {
      res.push_back(i.first);
    }
  }

  if (res.empty() || res.size() > 1) {
    cout << "Tie";
  } else {
    cout << res[0];
  }

  return 0;
}


