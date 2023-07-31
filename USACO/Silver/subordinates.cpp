#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "";
const int MAXN = 2*1e5 + 1;

vector<int> direct_subordinates[MAXN];
int subordinates[MAXN];

int count_subordinates(int cur_employee = 1) {
  for (int direct_subordinate: direct_subordinates[cur_employee]) {
    subordinates[cur_employee] += count_subordinates(direct_subordinate) + 1;
  }
  return subordinates[cur_employee];
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    int boss;
    cin >> boss;
    direct_subordinates[boss].push_back(i);
  }

  count_subordinates();
  for (int i = 1; i <= n; ++i) {
    cout << subordinates[i] << " ";
  }

  return 0;
}


