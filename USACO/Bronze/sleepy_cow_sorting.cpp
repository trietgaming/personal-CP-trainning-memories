#include <bits/stdc++.h>

using namespace std;

const string FNAME = "sleepy";

int arr[102], pos[101];
int n;

bool isSorted() {
  for (int i = 1; i <= n; ++i) {
    if (arr[i] != i) return false;
  }
  return true;
}

void pushTo(int k) {
  for (int i = 1; i < k; ++i) {
    pos[arr[i]] = i + 1;
    pos[arr[i + 1]] = i;
    swap(arr[i], arr[i + 1]);
  }
}

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    pos[arr[i]] = i;
  }
  arr[n + 1] = INT_MAX;

  int res = 0;
  int e = n;
  while (!isSorted()) {
//    for (int i = 1; i <= n; ++i) {
//      cout << arr[i] << " ";
//    }
//    cout << endl;
    while (e > 0 && pos[e] == e) {
      --e;
    }
    if (arr[1] == e) {
      pushTo(e);
    } else {
      int i = n;
      while (i > 2 && ((arr[1] < arr[i]))) {
        --i;
        if (arr[i] > arr[i + 1]) {
          break;
        };
      }
      pushTo(i);
    }
    ++res;
  }

  cout << res;

  return 0;
}


