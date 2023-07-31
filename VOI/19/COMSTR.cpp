#include <bits/stdc++.h>

using  namespace std;

using ll = long long;
const string FNAME = "COMSTR";
const int MAXM = 100000;

struct InitChar {
  char c;
  int ind;
  InitChar(char ch = 'A', int i = 0): c(ch), ind(i) {};
};

int diff_at[MAXM][26];
int total_diff[MAXM];
int appear[MAXM];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

// 	freopen((FNAME + ".inp").c_str(), "r", stdin);
// 	freopen((FNAME + ".out").c_str(), "w", stdout);

	ll m, m1, m2, r;
	cin >> m >> m1 >> m2 >> r;

	string s;
	cin >> s;

	vector<InitChar> fibo, prev;
  for (int i = 0; i < m2; ++i) {
    fibo.push_back(InitChar(s[i], i));
    prev.push_back(InitChar(s[i], i));
  }
  for (int i = m2; i < m2 + m1; ++i) {
    fibo.push_back(InitChar(s[i], i));
  }
  while (fibo.size() < m) {
    vector<InitChar> temp(prev.begin(), prev.end());
    prev.clear();
    for (InitChar c: fibo) prev.push_back(c);
    for (InitChar c: temp) fibo.push_back(c);
  }

  ll diff = 0;
  for (int i = m1 + m2; i < m; ++i) {
    if (fibo[i].c != s[i]) {
      ++diff_at[fibo[i].ind][s[i] - 'A'];
      ++total_diff[fibo[i].ind];
    }
    ++appear[fibo[i].ind];
    diff += fibo[i].c != s[i];
  }

  vector<pair<int, int>> most_appear;
  for (int i = 0; i < m1 + m2; ++i) {
    int max_diff = 0;
    for (int j = 0; j < 26; ++j) {
      max_diff = max(max_diff, diff_at[i][j]);
    }
    most_appear.push_back(pair<int, int>(max_diff, i));
  }
  sort(most_appear.begin(), most_appear.end(), greater<pair<int, int>>());
  for (int i = 0; i < r; ++i) {
    if (most_appear[i].first > appear[most_appear[i].second] - most_appear[i].first) {
      diff -= total_diff[most_appear[i].second];
      diff += appear[most_appear[i].second];
      diff -= most_appear[i].first;
    }
  }

  cout << diff;

	return 0;
}
