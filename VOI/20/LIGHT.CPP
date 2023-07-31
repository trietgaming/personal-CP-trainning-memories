#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "LIGHT";
const int INF = 1e9;
const int MAXNM = 400;
struct Rectangle {
  int top, left, bot, right;
  Rectangle(int t = - 1, int l = -1, int b = -1, int r = -1): top(t), left(l), bot(b), right(r) {};
};


/// 0 - Off, 1 - Green, 2 - Red
int grid[MAXNM][MAXNM], temp[MAXNM][MAXNM];
Rectangle recs[MAXNM][MAXNM];
int m, n, k;

void change(int &bulk, int time) {
  bulk += time;
  bulk %= 3;
}

struct SegmentTree {
  vector<vector<pair<int, int>>> st;
  int m, n;
  void build(int idr, int t, int b, int idc, int l, int r) {
    if (t == b) {
      if (l == r) {
        st[idr][idc].second = grid[t][l];
//        st[idr][idc].first = 0;
//        cerr << t << ", " << l << " = " << grid[t][l] << " - " << st[idr][idc].second << "\n";
        return;
      }
      int midh = (l + r) >> 1;
      build(idr, t, b, idc << 1, l, midh);
      build(idr, t, b, idc << 1 | 1, midh + 1, r);
      return;
    }
    int midv = (t + b) >> 1;
    build(idr << 1, t, midv, idc, l, r);
    build(idr << 1 | 1, midv + 1, b, idc, l, r);
  }
  SegmentTree(int r, int c): m(r), n(c), st(4 * r, vector<pair<int, int>>(4 * c, {0, 0})) {
    build(1, 1, m, 1, 1, n);
  };
  void pushr(int idr, int t, int b, int idc, int l, int r) {
    if (t != b) {
      st[idr << 1][idc].first += st[idr][idc].first;
      st[idr << 1 | 1][idc].first += st[idr][idc].first;
    }
    change(st[idr][idc].second, st[idr][idc].first);
    st[idr][idc].first = 0;
  }
  void pushc(int idr, int t, int b, int idc, int l, int r) {
    if (l!=r) {
      st[idr][idc << 1].first += st[idr][idc].first;
      st[idr][idc << 1 | 1].first += st[idr][idc].first;
    }
    change(st[idr][idc].second, st[idr][idc].first);
    st[idr][idc].first = 0;
  }
  int query(int idr, int t, int b, int idc, int l, int r, int qr, int qc) {
    pushr(idr, t, b, idc, l, r);
    if (t > qr || b < qr) return INF;
    if (t == b) {
      pushc(idr, t, b, idc, l, r);
      if (l > qc || r < qc) return INF;
      if (l == r) {
//        cerr << qr << ", " << qc << " = " << st[idr][idc].first << " - " << st[idr][idc].second << "\n";
        return st[idr][idc].second;
      }
      int midh = (l + r) >> 1;
      return min(query(idr, t, b, idc << 1, l, midh, qr, qc), query(idr, t, b, idc << 1 | 1, midh + 1, r, qr, qc));
    }
    int midv = (t + b) >> 1;
    return min(query(idr << 1, t, midv, idc, l, r, qr, qc), query(idr << 1 | 1, midv + 1, b, idc, l , r, qr, qc));
  }
  void add(int idr, int t, int b, int idc, int l, int r, int qt, int qb, int ql, int qr) {
    pushr(idr, t, b, idc, l, r);
    if (t > qb || b < qt) return;
    if (t >= qt && b <= qb) {
      pushc(idr, t, b, idc, l, r);
      if (l > qr || r < ql) return;
      if (l >= ql && r <= qr) {
          cerr << t << " " << b << ", " << l << " " << r << endl;
        st[idr][idc].first += 1;
        pushc(idr, t, b, idc, l, r);
        return;
      }
      int midh = (l + r) >> 1;
      add(idr, t, b, idc << 1, l, midh,  qt, qb,  ql,  qr);
      add(idr, t, b, idc << 1 | 1, midh + 1, r, qt, qb, ql, qr);
      return;
    }
    int midv = (t + b) >> 1;
    add(idr << 1, t, midv, idc, l, r, qt, qb, ql, qr);
    add(idr << 1 | 1, midv + 1, b, idc, l , r, qt, qb, ql, qr);
  }
};

int process(SegmentTree &st, int t) {
  int res = 0;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (recs[i][j].top == -1 && st.query(1, 1, m, 1, 1, n, i, j) != t) return INF;
      while (st.query(1, 1, m, 1, 1, n, i, j) != t) {
        st.add(1, 1, m, 1, 1, n, recs[i][j].top, recs[i][j].bot, recs[i][j].left, recs[i][j].right);
        ++res;
      }
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".inp").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> m >> n >> k;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      cin >> grid[i][j];
    }
  }
  for (int i = 0; i < k; ++i) {
    int r, c;
    cin >> r >> c;
    recs[r][c].top = r;
    recs[r][c].left = c;
    cin >> recs[r][c].bot >> recs[r][c].right;
  }

  ll res = INF;

  for (int t = 1; t <= 2; ++t) {

    SegmentTree st(m, n);
    ll mi = process(st, t);
//    cerr << mi << "\n";
//    res = min(res, mi);
  }

  cout << res;
  cerr << res;

  return 0;
}


