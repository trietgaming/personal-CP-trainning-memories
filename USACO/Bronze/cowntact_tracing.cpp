#include <bits/stdc++.h>

using namespace std;

// 1-based index

struct Event {
  int time, x, y;
};

Event interactions[250];

bool sortByTime(const Event &a, const Event &b) {
  return a.time < b.time;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("tracing.in", "r", stdin);
  freopen("tracing.out", "w", stdout);

  int n, t;
  cin >> n >> t;

  vector<int> f0s;
  vector<bool> isF0(n+1, false);

  for (int i = 1; i <= n; ++i) {
    char c;
    cin >> c;
    isF0[i] = c - '0';
    if (isF0[i]) {
      f0s.push_back(i);
    };
  }

  for (int i = 0; i < t; ++i) {
    Event &inter = interactions[i];
    cin >> inter.time >> inter.x >> inter.y;
  }

  sort(interactions, interactions + t, sortByTime);

  vector<pair<int,int>> validKs;

  vector<int> remains(n+1, 0);
  vector<bool> tempRes(n + 1, false);
  for (int k = 0; k <= t; ++k) {
    fill(tempRes.begin(), tempRes.end(), false);
    fill(remains.begin(), remains.end(), k);
    for (int f0: f0s) {
      bool push = true;
      tempRes[f0] = true;
      for (int e = 0; e < t; ++e) {
        Event &inter = interactions[e];
        bool xPos = tempRes[inter.x], yPos = tempRes[inter.y];
        if (!xPos && !yPos) continue;
        if (xPos) --remains[inter.x];
        if (yPos) --remains[inter.y];

        if (xPos && remains[inter.x] >= 0) {
          tempRes[inter.y] = true;
        }
        if (yPos && remains[inter.y] >= 0) {
          tempRes[inter.x] = true;
        }
      }

      for (int i = 1; i <=n; ++i) {
        if (tempRes[i] != isF0[i]) {
          push = false;
          break;
        }
      }

      if (push) {
        validKs.push_back(make_pair(f0, k));
      }
      fill(tempRes.begin(), tempRes.end(), false);
      fill(remains.begin(), remains.end(), k);
    }
  }

  int minK = INT_MAX, maxK = 0, f0, numF0 = 1;

  sort(validKs.begin(), validKs.end());
  f0 = validKs[0].first;

  for (pair<int, int> &k: validKs) {
    if (k.first != f0) {
      ++numF0;
      f0 = k.first;
    }
    minK = min(minK, k.second);
    maxK = max(maxK, k.second);
  }

  cout << numF0 << " " << minK << " ";
  if (maxK >= t) cout << "Infinity";
  else cout << maxK;

  return 0;
}
