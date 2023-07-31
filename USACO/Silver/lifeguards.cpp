#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
const int MAXN = 200002;

const string FNAME = "lifeguards";
pii lifeguards[MAXN];
map<int, int> compressed;

int lifeguardsNum[MAXN], prefixSumOnes[MAXN], realIndex[MAXN];

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> lifeguards[i].first >> lifeguards[i].second;
    compressed[lifeguards[i].first];
    compressed[lifeguards[i].second];
  }

  int compressedLength = 0;
  for (map<int, int>::iterator it = compressed.begin(); it != compressed.end(); ++it) {
    it->second = compressedLength;
    realIndex[compressedLength++] = it->first;
  }

  for (int i = 0; i < n; ++i) {
    lifeguardsNum[compressed[lifeguards[i].first] + 1]++;
    lifeguardsNum[compressed[lifeguards[i].second] + 1]--;
  }

  int coveredTimeWithoutFire = 0;
  for (int i = 1; i <= compressedLength; ++i) {
    lifeguardsNum[i] += lifeguardsNum[i-1];
    coveredTimeWithoutFire += (lifeguardsNum[i] > 0) * (realIndex[i] - realIndex[i-1]);
  }

  for (int i = 1; i <= compressedLength; ++i) {
    prefixSumOnes[i] = prefixSumOnes[i-1] + (lifeguardsNum[i] == 1) * (realIndex[i] - realIndex[i-1]);
  }

  int res = 0;

  for (int i = 0; i < n; ++i) {
    pii &toBeFired = lifeguards[i];
    int leaveUncoveredWhenFired = prefixSumOnes[compressed[toBeFired.second]] - prefixSumOnes[compressed[toBeFired.first]];
    res = max(res, coveredTimeWithoutFire - leaveUncoveredWhenFired);
  }

  cout << res;

  return 0;
}


