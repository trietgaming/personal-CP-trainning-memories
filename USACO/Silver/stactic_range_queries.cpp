#include <bits/stdc++.h>

using namespace std;

const string FNAME = "sum10e9";
const int MAXN = 100001;

struct Query {
  int l, r;
  long long val;
};

map<int, int> compressed;
int actual[4*MAXN+1];

long long comArr[4*MAXN+4], prefixSum[4*MAXN + 4];
Query adds[MAXN], prints[MAXN];

int main() {

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; ++i) {
    cin >> adds[i].l >> adds[i].r >> adds[i].val;
    compressed[adds[i].l] = 0;
    compressed[adds[i].r] = 0;
  }

  for (int i = 0; i < q; ++i) {
    cin >> prints[i].l >> prints[i].r;
    compressed[prints[i].l] = 0;
    compressed[prints[i].r] = 0;
  }

  int ci = 0;
  for (map<int, int>::iterator it = compressed.begin(); it != compressed.end(); ++it) {
    it->second = ci;
    actual[ci++] = it->first;
  }

  for (int i = 0; i < n; ++i) {
    comArr[compressed[adds[i].l] + 1] += adds[i].val;
    comArr[compressed[adds[i].r] + 1] -= adds[i].val;
  }

  comArr[0] = 0;
  for (int i = 1; i < ci; ++i) {
    comArr[i] += comArr[i-1];
  }

//  prefixSum[1] = comArr[1];
  for (int i = 1; i < ci; ++i) {
    prefixSum[i] = prefixSum[i-1] + (actual[i] - actual[i-1]) * comArr[i];
  }

  for (int i = 0; i < q; ++i) {
    cout << prefixSum[compressed[prints[i].r]] - prefixSum[compressed[prints[i].l]] << "\n";
  }

  return 0;
}


