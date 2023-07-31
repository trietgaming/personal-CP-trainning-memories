#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;

const string FNAME = "SSEQ";
const ll INF = 1e18;
const int MAXX = 2e6 + 5;
const int CORD = 1e6 + 1;

struct SegmentTree {
  vector<pii> st;
  SegmentTree(): st(4*MAXX) {}
  void push(int id) {
    st[id << 1].first += st[id].first;
    st[id << 1].second += st[id].first;
    st[id << 1 | 1].first += st[id].first;
    st[id << 1 | 1].second += st[id].first;
    st[id].first = 0;
  }
  void update(int id, int l, int r, int ul, int ur, int val) {
    if (l > ur || r < ul) return;
    if (l >= ul && r <= ur) {
      st[id].first += val;
      st[id].second += val;
      return;
    }
    push(id);
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, ul, ur, val);
    update(id << 1 | 1, mid + 1, r, ul, ur, val);
    st[id].second = max(st[id << 1].second, st[id << 1 | 1].second);
  }
};

struct Range {
  ll a, b;
  ll w;
  Range(ll l = 0, ll r = 0, ll weight = 0): a(l), b(r), w(weight) {}
};

vector<Range> lefts[MAXX];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  #ifdef LIONELMESSI
    freopen((FNAME + ".inp").c_str(), "r", stdin);
  #else
    freopen((FNAME + ".inp").c_str(), "r", stdin);
    freopen((FNAME + ".out").c_str(), "w", stdout);
  #endif

  int n;
  cin >> n;
  SegmentTree st;
  vector<Range> v;
  for (int i = 0; i < n; ++i) {
    ll a, b, w;
    cin >> a >> b >> w;
    st.update(1, 1, MAXX, b + CORD + 1, MAXX, w);
    lefts[a + CORD + 1].push_back(Range(a + CORD + 1, b + CORD + 1, w));
  }

  ll res = 0;
  for (int a = 1; a < MAXX; ++a) {
    for (Range b: lefts[a]) {
      res = max(res, st.st[1].second);
      st.update(1, 1, MAXX, b.b, MAXX, -b.w);
    }
  }

  cout << res;

  return 0;
}


