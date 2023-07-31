// DFS
#include <bits/stdc++.h>

using namespace std;

const string FNAME = "lineup";
const int NUMCOWS = 8;

unordered_map<string, int> cowToInt;
string cows[NUMCOWS] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
vector<int> g[NUMCOWS], res;
bool visited[NUMCOWS];

void init() {
  sort(cows, cows + NUMCOWS);
  for (int i = 0; i < NUMCOWS; ++i) {
    cowToInt[cows[i]] = i;
  }
}

void dfs(int &cow) {
  visited[cow] = true;
  res.push_back(cow);
  for (int i = 0; i < g[cow].size(); ++i) {
    int &neighbor = g[cow][i];
    if (visited[neighbor]) continue;
    dfs(neighbor);
  }
}

int main() {

  init();

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    string s1, s2;
    cin >> s1;
    cin >> s2 >> s2 >> s2 >> s2 >> s2;
    int c1 = cowToInt[s1], c2 = cowToInt[s2];
    g[c1].push_back(c2);
    g[c2].push_back(c1);
  }

  for (int i = 0; i < NUMCOWS; ++i) {
    if (visited[i] || g[i].size() == 2) continue;
    dfs(i);
  }

  for (int i: res) cout << cows[i] << endl;

  return 0;
}
