// Try using graph later

#include <bits/stdc++.h>

using namespace std;

const string FNAME = "swap";
const int MAXN = 100;

vector<int> edges[MAXN+1];
int n, k;

//temp algo
int arr[MAXN + 1], temp[MAXN + 1];

bool isSame() {
  for (int i = 0; i < n; ++i) {
    if (arr[i] != temp[i]) return false;
  }
  return true;
}

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n >> k;

  for (int i = 1; i <= n; ++i) {
    arr[i-1] = i;
    temp[i - 1] = i;
  }

  int a1, a2, b1, b2;
  cin >> a1 >> a2 >> b1 >> b2;

  int loop = 1;
  reverse(temp + a1 - 1, temp + a2);
  reverse(temp + b1 - 1, temp + b2);
  while (!isSame()) {
    reverse(temp + a1 - 1, temp + a2);
    reverse(temp + b1 - 1, temp + b2);
    ++loop;
  }

  int need = k % loop;

  while (need--) {
    reverse(arr + a1 - 1, arr + a2);
    reverse(arr + b1 - 1, arr + b2);
  }

  for (int i = 0; i < n; ++i) {
    cout << arr[i] << endl;
  }

  return 0;
}


