#include <bits/stdc++.h>

using namespace std;

int arr[5][4], res[5];
bool used[5][4];

void calcRes(int i, int c) {
  if (c > 24) return;
  res[i] = max(res[i], c);
}

void backtrack1(int i, int done, int current) {
  if (done == 4) {
    calcRes(i, current);
    return;
  }
  for (int j = 0; j < 4; ++j) {
    if (used[i][j]) continue;
    used[i][j] = true;
    backtrack1(i, done + 1, current + arr[i][j]);
    backtrack1(i, done + 1, current - arr[i][j]);
    backtrack1(i, done + 1, current * arr[i][j]);
    if (current % arr[i][j] == 0) backtrack1(i, done + 1, current / arr[i][j]);
    used[i][j] = false;
  }
}

void backtrack2(int i, int done, int c1, int c2, bool completed = false) {

  if (done == 2) {
    if (completed) {
      calcRes(i, c1 + c2);
      calcRes(i, c1 - c2);
      calcRes(i, c1 * c2);
      if (c2 != 0 && c1 % c2 == 0) calcRes(i, c1 / c2);
      return;
    }
    for (int j = 0; j < 4; ++j) {
      if (used[i][j]) continue;
      used[i][j] = true;
      backtrack2(i, 1, c1, arr[i][j], true);
      used[i][j] = false;
    }
    return;
  }

  int &current = completed? c2: c1;
  for (int j = 0; j < 4; ++j) {
    if (used[i][j]) continue;
    used[i][j] = true;
    current += arr[i][j];
    backtrack2(i, done + 1, c1, c2, completed);
    current -= 2 * arr[i][j];
    backtrack2(i, done + 1, c1, c2, completed);
    current += arr[i][j];
    current *= arr[i][j];
    backtrack2(i, done + 1, c1, c2, completed);
    current /= arr[i][j];
    if (current % arr[i][j] == 0) {
      current /= arr[i][j];
      backtrack2(i, done + 1, c1, c2, completed);
      current *= arr[i][j];
    };
    used[i][j] = false;
  }
}

int main() {

  int n; cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 4; ++j) {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 4; ++j) {
      used[i][j] = true;
      backtrack1(i, 1, arr[i][j]);
      backtrack2(i, 1, arr[i][j], 0);
      used[i][j] = false;
    }
    cout << res[i] << endl;
  }

  return 0;
}
