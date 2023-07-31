#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "snowboots";
const int MAXN = 100000;


struct Boot {
  int depth, step, ind;
};
bool cmpBoot(const Boot &a, const Boot &b) {
  return a.depth > b.depth;
}

int tiles[MAXN], tilesIndSortedDes[MAXN];

bool sortInd(const int &a, const int &b) {
  return tiles[a] > tiles[b];
}

bool result[MAXN];
Boot boots[MAXN];
set<int> reachableTilesInd;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, b;
  cin >> n >> b;

  for (int i = 0; i < n; ++i) {
    cin >> tiles[i];
    tilesIndSortedDes[i] = i;
    reachableTilesInd.insert(i);
  }

  for (int i = 0; i < b; ++i) {
    cin >> boots[i].depth >> boots[i].step;
    boots[i].ind = i;
  }

  sort(tilesIndSortedDes, tilesIndSortedDes + n, sortInd);

  // boots[0] max depth, boot[b-1] min depth
  sort(boots, boots + b, cmpBoot);

  int curLargestTileInd = 0;
  int minStepRequired = 1;

  for (int i = 0; i < b; ++i) {
    while (curLargestTileInd < n && tiles[tilesIndSortedDes[curLargestTileInd]] > boots[i].depth) {
      set<int>::iterator actualIterOfCurTile = reachableTilesInd.find(tilesIndSortedDes[curLargestTileInd]);
      minStepRequired = max(minStepRequired, *next(actualIterOfCurTile) - *prev(actualIterOfCurTile));
      reachableTilesInd.erase(actualIterOfCurTile);
      ++curLargestTileInd;
    }
    result[boots[i].ind] = minStepRequired <= boots[i].step;
  }

  for (int i = 0; i < b; ++i) cout << result[i] << "\n";

  return 0;
}


