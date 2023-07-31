#include <bits/stdc++.h>

using namespace std;

const string FNAME = "goodsub";
const int MAXN = 100001;

long long prefixSum[MAXN];
unordered_map<long long, long long> countSum;

void calc() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    char c;
    cin >> c;
    prefixSum[i] = prefixSum[i-1] + (c - '0');
  }
  // Case subArr length 1
  countSum[0] = 1;
  for (int i = 1; i <= n; ++i) {
    ++countSum[prefixSum[i] - i];
  }
  long long goods = 0;
  for (pair<long long, long long> i: countSum) {
    // to hop chap 2 = N!/(K!)(N-K)! = N!/2*(N -2)! = N!/(N-2)! * (1/2)! = (N * (N-1))/2
    if (i.second < 2) continue;
    goods += i.second * (i.second - 1) / 2;
  }
  cout << goods << endl;
  countSum.clear();
}

int main() {

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);


  int q; cin >> q;
  while (q--) {
    calc();
  }

  return 0;
}

