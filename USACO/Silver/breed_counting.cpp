#include <bits/stdc++.h>

using namespace std;

const string FNAME = "bcount";
const int MAXN = 1000000;

int one[MAXN], two[MAXN], three[MAXN];

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n, q;
  cin >> n >> q;

  for (int i = 1; i <= n; ++i) {
    int a; cin >> a;
    one[i] = one[i-1];
    two[i] = two[i-1];
    three[i] = three[i-1];
    if (a == 1) one[i]++;
    else if (a == 2) two[i]++;
    else three[i]++;
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << one[r] - one[l-1] << " ";
    cout << two[r] - two[l-1] << " ";
    cout << three[r] - three[l-1] << "\n";
  }

  return 0;
}


