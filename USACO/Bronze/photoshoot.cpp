#include <bits/stdc++.h>

using namespace std;

const string FNAME = "photoshoot";
const int MAXN = 200001;

// 1 - G, 0 - H
bool arr[MAXN];

int main() {

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    char c;
    cin >> c;
    arr[i] = c - 'G';
  }

  vector<bool> simple;
  for (int i = 1; i <= n; i+=2) {
    if (arr[i] && !arr[i+1] && (simple.empty() || !simple.back())) {
        //HG
      simple.push_back(1);
    } else if (!arr[i] && arr[i+1] && (simple.empty() || simple.back())) {
        //GH
      simple.push_back(0);
    }
  }

  if (!simple.empty() && simple.back()) simple.pop_back();

  cout << simple.size();

  return 0;
}


