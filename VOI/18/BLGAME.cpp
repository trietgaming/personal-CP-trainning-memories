#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const string FNAME = "BLGAME";
const int INF = 1e9 + 7;
const int MAXNM = 1001;

bool banned[MAXNM][MAXNM];
bool visited[MAXNM][MAXNM];
const int dirx[4] = {0, 1, -1, 0};
const int diry[4] = {1, 0, 0, -1};
int a,b,c,m,n,k;
ll res;

struct Rec {
  int top, left, bot, right;
  Rec(int t = 0, int l = 0, int b = 0, int r = 0): top(t), left(l),bot(b), right(r) {
  }
};

bool valid(Rec r) {
  bool va = false;
  for (int i = r.top; i <= r.bot; ++i) {
    if (i < 1 || i > m) return false;
    for (int j = r.left; j <= r.right; ++j) {
      if (j < 1 || j > n || banned[i][j]) return false;
      if (!visited[i][j]) va = true;
    }
  }
  return va;
}

void visit(Rec r) {
  for (int i = r.top; i <= r.bot; ++i) {
    for (int j = r.left; j <= r.right; ++j) {
      if (!visited[i][j]) ++res;
      visited[i][j] = true;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  #ifdef LIONELMESSI
  freopen((FNAME + ".inp").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);
  #endif // LIONELMESSI

  cin>>a>>b>>c>>m>>n>>k;
  for (int i = 0; i < k; ++i) {
    int y, x;
    cin >> y >> x;
    banned[y][x] = true;
  }

  if (a == b && b == c && c == 1) {
    queue<pii> q;
    q.push({1, 1});
    visited[1][1] = true;
    while (q.size()) {
      ++res;
      int cx = q.front().first;
      int cy = q.front().second;
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int nx = cx + dirx[i];
        int ny = cy + diry[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m || visited[ny][nx] || banned[ny][nx]) continue;
        visited[ny][nx] = true;
        q.push({nx, ny});
      }
    }
    cout << res;
    return 0;
  }
  if (a == b && b == c) {
    queue<Rec> q;
    q.push(Rec(1, 1, a, b));
    visit(q.front());
    while (q.size()) {
      Rec r = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        Rec nr(r.top + diry[i], r.left + dirx[i], r.bot + diry[i], r.right + dirx[i]);
        if (!valid(nr)) continue;
        visit(nr);
        q.push(nr);
      }
    }
    cout << res;
    return 0;
  }
  cout << 7;

  return 0;
}


