#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;

struct Day {
  int d;
  string name;
  int m;
};

Day arr[MAXN];
int score[3] = {7, 7, 7};

int &getScore(string &name) {
    if (name == "Bessie") return score[0];
    if (name == "Elsie") return score[1];
    return score[2];
}

bool cmp(const Day &a, const Day &b) {
  return a.d < b.d;
}

int main() {
  freopen("measurement.in", "r", stdin);
  freopen("measurement.out", "w", stdout);

  int n; cin >> n;

  for (int i = 0; i < n; ++i) {
    Day &t = arr[i];
    cin >> t.d >> t.name >> t.m;
  }

  sort(arr, arr + n, cmp);

  set<int> bestCow({0, 1, 2});

  int res = 0;

  for (int i = 0; i < n; ++i) {
    Day &day = arr[i];
    getScore(day.name) += day.m;
    set<int> currentMax;
    currentMax.insert(0);
    for (int j = 1; j < 3; ++j) {
      int &mCow = score[*(--currentMax.end())];
      if (mCow == score[j]) currentMax.insert(j);
      else if (mCow < score[j]) {
        currentMax.clear();
        currentMax.insert(j);
      }
    }

    res += currentMax != bestCow;
    bestCow = currentMax;
  }

  cout << res;

  return 0;
}
