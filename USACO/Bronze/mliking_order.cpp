#include <bits/stdc++.h>

using namespace std;

const string FNAME = "milkorder";

int order[101], pick[101], pane[101];

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, m, k;
  cin >> n >> m >> k;

  int oneOrder = -1;
  for (int i = 0; i < m; ++i) {
    cin >> order[i];
    if (order[i] == 1) oneOrder = i;
  }

  for (int i = 0, c, p; i < k; ++i) {
    cin >> c >> p;
    pick[c] = p;
    pane[p] = c;
    if (c == 1) {
      cout << p;
      return 0;
    }
  }


  if (oneOrder != -1) {
    int prev = 0;
    for (int i = 0; i <= oneOrder; ++i) {
      if (!pick[order[i]]) {
        for (int pos = prev + 1; pos <= n; ++pos) {
          if (!pane[pos]) {
            pick[order[i]] = pos;
            pane[pos] = order[i];
            break;
          }
        }
      }
      prev = pick[order[i]];
    }
    cout << prev;
    return 0;
  }

  for (int i = 0; i < m; ++i) {
    if (pick[order[i]]) {
      int pos = pick[order[i]], j = i;
      while (j >= 0 && pos >= 1) {
        while ((j >= 0 && pick[order[j]])) --j;
        while (pos >= 1 && pane[pos]) --pos;
        if (j >= 0 && pos >= 1) {
          pick[order[j]] = pos;
          pane[pos] = order[j];
        }
      }
    }
  }

  for (int i = m - 1; i >= 0; --i) {
    if (!pick[order[i]]) {
      for (int pos = n; pos >= 1; --pos) {
        if (!pane[pos]) {
          pane[pos] = order[i];
          pick[order[i]] = pos;
          break;
        }
      }
    }
  }

//  for (int i = 1; i <= n; ++i) {
//    cout << pane[i] << " ";
//  }

  for (int i = 1; i <= n; ++i) {
    if (!pane[i]) {
      cout << i;
      return 0;
    }
  }


  return 0;
}


