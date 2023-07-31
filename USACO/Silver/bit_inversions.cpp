#include <bits/stdc++.h>

using namespace std;

const string FNAME = "inversebit";
set<int> substrs;
multiset<int> lengths;

void consider(int ind) {
  if (ind == 0 || ind == *substrs.rbegin()) return;
  auto it = substrs.find(ind);
  if (it != substrs.end()) {
    auto lo = it, up = it;
    --lo; ++up;
    lengths.erase(lengths.find(*up - ind));
    lengths.erase(lengths.find(ind - *lo));
    lengths.insert(*up - *lo);
    substrs.erase(it);
  } else {
    auto up = substrs.upper_bound(ind), lo = up;
    lo--;
    lengths.erase(lengths.find(*up - *lo));
    substrs.insert(ind);
    lengths.insert(*up - ind);
    lengths.insert(ind - *lo);
  }
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  string bits;
  cin >> bits;
  bits += "2";

  substrs.insert(0);

  for (int i = 1, cur = 0; i < bits.length(); ++i) {
    int bit = bits[i] - '0';
    if (bit != bits[cur] - '0') {
      substrs.insert(i);
      lengths.insert(i - cur);
      cur = i;
    }
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; ++i) {
    int ind;
    cin >> ind;
    consider(ind - 1);
    consider(ind);
    cout << *lengths.rbegin() << " ";
  }


  return 0;
}


