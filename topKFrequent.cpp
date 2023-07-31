#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10001;
int feq[MAXN*2] = {0};

int main() {
  int n, k;
  cin >> n >> k;
  int nums[10000];
  for (int i = 0; i < n; ++i) cin >> nums[i];

      for (int i = 0; i < n; ++i) {
          nums[i] += 10000;
      }
      for (int i = 0; i < n; ++i) {
          cout << feq[nums[i]] << " ";
          ++feq[nums[i]];
      }
      vector<int> res;
      for (int i = 0; i <= 20000; ++i) {
          if (feq[i] >= k) cout << (i - 10000) << " ";
      }
};
