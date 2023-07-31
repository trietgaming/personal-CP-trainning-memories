#include <bits/stdc++.h>

using namespace std;

const string FNAME = "";

int main() {

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int Q;
  cin >> Q;

  unordered_map<long long, long long> mp;

  while (Q--) {
    long long t, k, v;

    cin >> t >> k;
    if (t) {
      cout << mp[k] << "\n";
    } else{
      cin >> v;
      mp[k] = v;
    }

  }


  return 0;
}

