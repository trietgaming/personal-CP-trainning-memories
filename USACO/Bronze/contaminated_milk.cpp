#include <bits/stdc++.h>

using namespace std;

struct Event {
  int p;
  int m;
  int t;
};

// Sort by time
bool cmp(Event &a, Event &b) {
  return a.t < b.t;
}

Event transcript[1001], sickEvents[51];
bool sicked[51];

bool drank[51][51];

int main() {

  freopen("badmilk.in", "r", stdin);
  freopen("badmilk.out", "w", stdout);

  int N, M, D, S;
  cin >> N >> M >> D >> S;

  for (int i = 0; i < D; ++i) {
    Event &e = transcript[i];
    cin >> e.p >> e.m >> e.t;
    drank[e.p][e.m] = true;
  }

  for (int i = 0; i < S; ++i) {
    cin >> sickEvents[i].p >> sickEvents[i].t;
    sicked[sickEvents[i].p] = true;
  }

  sort(transcript, transcript + D, cmp);
  sort(sickEvents, sickEvents + S, cmp);

  set<int> maybeBad;
  for (int m = 1; m <= M; ++m) {
    maybeBad.insert(m);
  }

  for (int i = 0; i < S; ++i) {
    set<int> temp, inter;
    int timeSick = sickEvents[i].t;
    int whoSicked = sickEvents[i].p;
    for (int j = 0; j < D; ++j) {
      if (transcript[j].t < timeSick && transcript[j].p == whoSicked)
        temp.insert(transcript[j].m);
    }
    for (set<int>::iterator it = maybeBad.begin(); it != maybeBad.end(); ++it) {
      if (temp.count(*it)) inter.insert(*it);
    }
    maybeBad = inter;
  }

  vector<int> unsicked;
  for (int i = 1; i <= N; ++i) {
    if (sicked[i]) continue;
    unsicked.push_back(i);
  }

  int res = S;

  for (int badMilk: maybeBad) {
    int temp = S;
    for (int p: unsicked) {
      if (drank[p][badMilk]) {
        ++temp;
      };
    }
    res = max(res, temp);
  }

  cout << res;

  return 0;
}
