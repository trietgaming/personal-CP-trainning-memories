#include <bits/stdc++.h>

using namespace std;

const string FNAME = "subdiv";
const int MAXN = 200000;

long long modCounts[MAXN + 1], arr[MAXN + 1];

int main() {

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  long long n;
  cin >> n;

  long sum = 0, sumMod = 0, res = 0;

  modCounts[0] = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    sum += arr[i];
    sumMod = (sum % n + n) % n;
    res += modCounts[sumMod];
    ++modCounts[sumMod];
  }

  cout << res;

  return 0;
}


