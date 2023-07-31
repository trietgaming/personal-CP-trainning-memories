#include <bits/stdc++.h>

using namespace std;

vector<int> lines[256];

int main() {

  freopen("circlecross.in", "r", stdin);
  freopen("circlecross.out", "w", stdout);

  string s;
  cin >> s;

  for (int i = 0; i < s.length(); ++i) {
    lines[s[i]].push_back(i);
  }

  int counter = 0;

  for (char i = 'A'; i <= 'Z'; ++i) {
    for (char j = 'A'; j <= 'Z'; ++j) {
      counter += lines[i][0] < lines[j][0] && lines[j][0] < lines[i][1] && lines[i][1] < lines[j][1];
    }
  }

  cout << counter;

  return 0;
}
