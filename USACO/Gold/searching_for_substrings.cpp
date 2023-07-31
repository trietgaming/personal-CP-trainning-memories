#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using lll = __int128;

const string FNAME = "";
const int INF = 1e9 + 7;
//const int MAXN =;

struct HashString {
  lll MOD = (1LL << 61) - 1;
  lll BASE = 1e9+7;
  vector<lll> pows, prefix_hashes;
  ll n;
  HashString(string &s): pows(s.length() + 1), prefix_hashes(s.length() + 1), n(s.length()) {
    pows[0] = 1;
    for (int i = 1; i <= n; ++i) {
      pows[i] = (pows[i - 1] * BASE) % MOD;
    }
    for (int i = 1; i <= n; ++i) {
      prefix_hashes[i] = (((prefix_hashes[i - 1] * BASE) % MOD) + s[i - 1]) % MOD;
    }
  }
  ll get_hash(int l, int r) {
    lll t = prefix_hashes[r + 1] - (prefix_hashes[l] * pows[r - l + 1]);
    return (t + MOD * MOD) % MOD;
  }
};

ll feqN[256], feqH[256];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  string n, h;
  cin >> n >> h;

  for (char c: n) {
    ++feqN[c];
  }

  HashString hHash(h);

  set<ll> matches;

  for (int i = 0; i < n.length() - 1; ++i) {
    ++feqH[h[i]];
  }

  for (int i = n.length() - 1; i < h.length(); ++i) {
    ++feqH[h[i]];
    bool matched = true;
    for (int j = 'a'; j <= 'z'; ++j) {
      if (feqH[j] != feqN[j]) {
        matched = false;
        break;
      }
    }
    if (matched) {
      matches.insert(hHash.get_hash(i - n.length() + 1, i));
    }
    --feqH[h[i - n.length() + 1]];
  }

  cout << matches.size();

  return 0;
}


