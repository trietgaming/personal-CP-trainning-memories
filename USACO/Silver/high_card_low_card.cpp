#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "cardgame";
const int MAXN = 50000;

int elsies[MAXN];
bool used[2*MAXN+1];
vector<int> bessies1, bessies2;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> elsies[i];
    used[elsies[i]] = true;
  }

  for (int i = 1, cur = 0; i <= n << 1; ++i) {
    if (!used[i]) {
      if (cur <= n) {
        bessies1.push_back(i);
      }
      else bessies2.push_back(i);
      ++cur;
    }
  }

  sort(elsies, elsies + n/2, greater<int>());
  sort(elsies + n/2, elsies + n, greater<int>());
  sort(bessies1.begin(), bessies1.end(), greater<int>());
  sort(bessies2.begin(), bessies2.end(), greater<int>());

  int res = 0;
  for (int i = 0, j = 0; i < n >> 1 && j < n >> 1; ++i) {
    if (bessies1[j] > elsies[i]) {
      ++res;
      ++j;
    }
  }

  for (int i = n >> 1, j = n >> 1; i < n && j < n; ++j) {
    if (bessies1[j] < elsies[i]) {
      ++res;
      ++i;
    }
  }

  cout << res;

  return 0;
}


