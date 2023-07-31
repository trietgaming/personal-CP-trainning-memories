#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "meeting";
const int MAXN = 60000;

struct Friend {
  ll pos, max_speed;
};

Friend friends[MAXN];
int n;

bool can_all_friends_be_gathered_within(double seconds) {
  double posl = 0, posr = 1e9;
  while (posl < posr && posr - posl >= 0.000001) {
    double mid = (posl + posr) / 2;
    bool cant_move_up = 0, cant_move_down = 0;
    for (int i = 0; i < n; ++i) {
      if (friends[i].pos == mid) continue;
      if (friends[i].pos < mid && ((double) friends[i].pos) + ((double) friends[i].max_speed) * seconds < mid) cant_move_up = true;
      else if (friends[i].pos > mid && ((double) friends[i].pos) - ((double) friends[i].max_speed) * seconds > mid) cant_move_down = true;
    }
    if (cant_move_down && cant_move_up) return false;
    if (cant_move_down) {
      posl = mid;
    }
    else if (cant_move_up) {
      posr = mid;
    }
    else return true;
  }
  return true;
}

double find_min_second_to_gather_all_friends(double l, double r) {
  if (l == r) return l;
  if (r - l < (double) 0.000001) return (l + r) / 2;
  double mid = (l + r) / 2;
  if (can_all_friends_be_gathered_within(mid)) return find_min_second_to_gather_all_friends(l, mid);
  return find_min_second_to_gather_all_friends(mid, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> friends[i].pos;
  }
  for (int i = 0; i < n; ++i) {
    cin >> friends[i].max_speed;
  }

  cout.precision(12);
  cout << find_min_second_to_gather_all_friends(0, 1e9);

  return 0;
}


