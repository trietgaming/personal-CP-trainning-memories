#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "convention2";

struct Cow {
  int ind, s, e;
};

bool cmp(const Cow &a, const Cow &b) {
  return a.s > b.s;
}

bool operator <(const Cow &a, const Cow &b) {
  return a.ind > b.ind;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  priority_queue<Cow> waiting;
  vector<Cow> cows;

  for (int i = 0; i < n; ++i) {
    Cow c;
    cin >> c.s >> c.e;
    c.ind = i;
    cows.push_back(c);
  }

  sort(cows.begin(), cows.end(), cmp);

  int current = cows.back().e + cows.back().s, res = 0;
  cows.pop_back();

  while (!cows.empty()) {
    if (cows.back().s >= current) {
      current = cows.back().e + cows.back().s;
      cows.pop_back();
      continue;
    }
    while (!cows.empty() && cows.back().s < current) {
      waiting.push(cows.back());
      cows.pop_back();
    }
    while (!waiting.empty()) {
//        cout << waiting.top().s << " ";
      res = max(res, current - waiting.top().s);
      current = current + waiting.top().e;
      waiting.pop();
      while(!cows.empty() && cows.back().s < current) {
        waiting.push(cows.back());
        cows.pop_back();
      }
    }
  }

  cout << res;

  return 0;
}


