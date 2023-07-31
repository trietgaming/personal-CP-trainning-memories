#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "COMSTR";
const int INF = 1e9 + 7;
//const int MAXN =;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

ll rdrange(ll l, ll r) {
  return uniform_int_distribution<ll>(l, r)(rd);
}

const int NUMTEST = 100;

int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  for (int iT = 0; iT < NUMTEST; ++iT) {
    ofstream inp(FNAME+".inp");

    int m, m1, m2, r;
    m = rdrange(2, 1000);
    m1 = rdrange(1, 9);
    m2 = rdrange(1, 10 - m1);
    r = m1 + m2;
    string s;
    for (int i = 0; i < m; ++i) {
      s += rdrange(0,1) + 'A';
    }

    inp << m << " " << m1 << " " << m2 << " " << r <<  "\n" << s;

    inp.close();
    system((FNAME + ".exe").c_str());
    system((FNAME + "_ans.exe").c_str());
    if (system(("fc " + FNAME +".out "+FNAME+".ans").c_str())) {
      return 0;
    }
  }

  return 0;
}

