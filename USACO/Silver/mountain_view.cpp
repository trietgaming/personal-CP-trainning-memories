#include <bits/stdc++.h>

using namespace std;

const string FNAME = "mountains";
const int MAXN = 100000;

struct Mountain {
  int left, right;
  Mountain(int l, int r) {
    left = l;
    right = r;
  }
  Mountain() {};
};

Mountain mountains[MAXN];

bool cmpMountain(Mountain &a, Mountain &b){
  if (a.left == b.left) return a.right > b.right;
  return a.left < b.left;
}

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    mountains[i] = Mountain(x - y, x + y);
  }

  sort(mountains, mountains + n, cmpMountain);

  int rightMost = -1;
  int res = 0;

  for (int i = 0; i < n; ++i) {
    if (mountains[i].right > rightMost) {
      ++res;
      rightMost = mountains[i].right;
    }
  }

  cout << res;

  return 0;
}


