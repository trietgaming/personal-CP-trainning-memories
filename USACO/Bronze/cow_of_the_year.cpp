#include <bits/stdc++.h>

using namespace std;

const string FNAME = "coty";

unordered_map<string, int> zodiac({
                                    {"Ox", 0},
                                    {"Tiger", 1},
                                    {"Rabbit", 2},
                                    {"Dragon", 3},
                                    {"Snake", 4},
                                    {"Horse", 5},
                                    {"Goat", 6},
                                    {"Monkey", 7},
                                    {"Rooster", 8},
                                    {"Dog", 9},
                                    {"Pig", 10},
                                    {"Rat", 11}
                                  });


int main() {

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n; cin >> n;
  unordered_map<string, pair<int, int>> mp;
  mp["Bessie"].first = 0;
  mp["Bessie"].second = 0;

  string s1, s2, animal, order, junk;
  for (int i = 0; i < n; ++i) {
    cin >> s1;
    for (int j = 0; j < 2; ++j) cin >> junk;
    cin >> order >> animal;
    for (int j = 0; j < 2; ++j) cin >> junk;
    cin >> s2;

    pair<int,int> &a = mp[s1], &b = mp[s2];
    int g1 = b.second, g2 = zodiac[animal];
    a.second = g2;
    if (order == "previous") {
      a.first = b.first - (g1 - g2);
      if (g1 <= g2) {
        a.first -= 12;
      }
    } else {
      a.first = b.first + (g2 - g1);
      if (g1 >= g2) {
        a.first += 12;
      }
    }
  }

  cout << abs(mp["Elsie"].first);

  return 0;
}


