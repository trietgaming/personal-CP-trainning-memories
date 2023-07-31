#include <bits/stdc++.h>

using namespace std;

const string FNAME = "customers";
const int MAXN = 400004;

pair<long long, long long> customers[MAXN];
long long events[MAXN];
map<long long, long long> compressed;

int main() {

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  long long n; cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> customers[i].first >> customers[i].second;
    compressed[customers[i].first];
    compressed[customers[i].second];
  }

  long long compressedN = 0;
  for (auto it = compressed.begin(); it != compressed.end(); ++it) {
    it->second = compressedN++;
  }

  for (long long i = 0; i < n; ++i) {
    events[compressed[customers[i].first]]++;
    events[compressed[customers[i].second]]--;
  }

  long long cur = 0, res = 0;
  for (long long i = 0; i < compressedN; ++i) {
    cur += events[i];
    res = max(res, cur);
  }

  cout << res;

  return 0;
}


