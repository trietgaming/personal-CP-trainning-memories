#include <bits/stdc++.h>

using namespace std;

const string FNAME = "jury";

const int MAXK = 2000;

long long juryMarks[MAXK], polycarpRems[MAXK];

int main() {

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int k, n;
  cin >> k >> n;

  for (int i = 0; i < k; ++i) {
    cin >> juryMarks[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> polycarpRems[i];
  }

  unordered_set<long long> res;

  for (int i = 0, past = 0; i < k; ++i) {
    past += juryMarks[i];
    unordered_set<long long> temp;
    long long maybe = polycarpRems[0] - past;
    long long cur = maybe;
    for (int j = 0; j < k; ++j) {
      cur += juryMarks[j];
      temp.insert(cur);
    }
    bool shouldInsert = true;
    for (int j = 0; j < n; ++j) {
      if (!temp.count(polycarpRems[j])) {
        shouldInsert = false;
        break;
      }
    }

    if (shouldInsert) res.insert(maybe);
  }

  cout << res.size();

  return 0;
}


