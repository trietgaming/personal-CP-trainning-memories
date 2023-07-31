#include <bits/stdc++.h>

using namespace std;

const string FNAME = "whereami";
int n;
string s;

bool ok(unordered_set<string> &st, int l) {
  for (int i = 0; i < n - l + 1; ++i) {
    string t = s.substr(i, l);
    if (st.count(t)) return false;
    st.insert(t);
  }
  return true;
}

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n;
  cin >> s;

  for (int l = 1; l <= n; ++l) {
    unordered_set<string> st;
    if (ok(st, l)) {
      cout << l;
      break;
    }
    st.clear();
  }

  return 0;
}


