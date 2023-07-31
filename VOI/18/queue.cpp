#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "QUEUE";
const int INF = 1e9 + 7;
const int MAXNM = 50000 + 10;

pii taken[MAXNM];
pii buses[MAXNM];

bool greed(pii bus) {
  for (int j = bus.first; j <= bus.second; ++j) {
    if (!taken[j].first) {
      taken[j] = bus;
      return true;
    }

    bool takeable = false;
    for (int l = taken[j].first; l <= taken[j].second; ++l) {
      if (!taken[l].first) {
          taken[l] = taken[j];
          takeable = true;
          break;
      }
    }
    if (takeable) {
      taken[j] = bus;
      return true;
    }
  }
  return false;
}

void process() {
  int m, n;
  cin >> m >> n;
  fill(taken, taken + m + 1, pii(0,0));
  for (int i = 0; i < n; ++i) {
    cin >> buses[i].first >> buses[i].second;
  }
  for (int i = 0; i < n; ++i) {
    if (!greed(buses[i])) {
      cout << i;
      return;
    };
  }
  cout << n;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
#ifdef LIONELMESSI
  freopen((FNAME + ".inp").c_str(), "r", stdin);
#endif

  int T;
  cin >> T;
  while (T--) {
    process();
    cout << "\n";
  }

  return 0;
}

