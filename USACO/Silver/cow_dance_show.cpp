#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "cowdance";
const int MAXN = 10000;

int arr[MAXN];
int n, tmax;

bool checkK(int k) {
  priority_queue<int, vector<int>, greater<int>> q;
  for (int i = 0; i < k; ++i) {
     q.push(arr[i]);
  }
  for (int i = k; i < n; ++i) {
    int top = q.top();
    q.pop();
    q.push(arr[i] + top);
  }
  int maxK;
  while (!q.empty()) {
    maxK = q.top();
    q.pop();
  }
  return maxK <= tmax;
}

int searchForK(int l, int r) {
  if (l == r) {
    return r;
  }
  int mid = (l + r) / 2;
  bool noMoreK = checkK(mid);
  if (noMoreK) {
    return searchForK(l, mid);
  }
  return searchForK(mid + 1, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n >> tmax;

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  int res = searchForK(1, n);

  cout << res;

  return 0;
}


