#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "";
const int MAXN = 200000;

struct Task {
  ll duration, deadline;
};

bool cmp(const Task &a, const Task &b) {
  return a.duration < b.duration;
}

Task tasks[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> tasks[i].duration >> tasks[i].deadline;
  }

  sort(tasks, tasks + n, cmp);

  ll curTime = 0, res = 0;

  for (int i = 0; i < n; ++i) {
    curTime += tasks[i].duration;
    res += tasks[i].deadline - curTime;
  }

  cout << res;

  return 0;
}


