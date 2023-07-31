#include <bits/stdc++.h>
using namespace std;

int main() {

  int m;
  cin >> m;

  set<int> res;

  for (int i = 0, k; i < m; ++i) {
    cin >> k;
    for (int j = 0, temp; j < k; ++j) {
      cin >> temp;
      res.insert(temp);
    }
  }

  for (set<int>::const_iterator i = res.cbegin(), e = res.cend(); i != e; ++i) {
    cout << *i << " ";
  }

  return 0;
}
