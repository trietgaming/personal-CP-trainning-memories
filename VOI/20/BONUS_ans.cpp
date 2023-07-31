#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "BONUS";
const int INF = 1e9 + 7;
//const int MAXN =;

ll n, k;
ll res = 0;

void backtrack(vector<int> gifts, int chosen, ll curPoint) {
  if (chosen == k) {
    res = max(res, curPoint);
    return;
  }
  if (gifts.size() < 2) return;
  backtrack(vector<int>(gifts.begin() + 2, gifts.end()), chosen + 1, curPoint + abs(gifts[0] - gifts[1]));
  backtrack(vector<int>(gifts.begin(), gifts.end() - 2), chosen + 1, curPoint + abs(gifts[gifts.size() - 1] - gifts[gifts.size() - 2]));
  backtrack(vector<int>(gifts.begin() + 1, gifts.end() - 1), chosen + 1, curPoint + abs(gifts[0] - gifts[gifts.size() - 1]));
  backtrack(vector<int>(gifts.begin() + 1, gifts.end()), chosen, curPoint);
  backtrack(vector<int>(gifts.begin(), gifts.end() - 1), chosen, curPoint);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".inp").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n >> k;
  vector<int> gifts;
  for (int i = 0; i < n; ++i) {
    int t; cin >> t;
    gifts.push_back(t);
  }

  backtrack(gifts, 0, 0);

  cout << res;

  return 0;
}


