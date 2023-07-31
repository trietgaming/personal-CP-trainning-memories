#include <bits/stdc++.h>

using namespace std;

#define MAXN 200000

int n;
int arr[MAXN];

bool cmp(int a, int b) {
  return a < b;
}

int main() {

  ifstream inp("DESERT.inp");
  inp >> n;
  for (int i = 0; i < n; ++i) {
    inp >> arr[i];
  }

  inp.close();

  int posBottles = 0;
  int health = 0;
  int res = 0;
  priority_queue<int, vector<int>, greater<int> > q;
  int current = 0;

  for (int i = 0; i < n; ++i) {

    priority_queue<int, vector<int>, greater<int> > cl = q;
    while (!cl.empty()) {
      cout << cl.top() << " ";
      cl.pop();
    }
    cout << endl;

    if (arr[i] >= 0) {
      health += arr[i];
      current++;
      res = max(res, posBottles);
      continue;
    }

    if (health + arr[i] < 0 && !q.empty() && health - q.top() + arr[i] >= 0) {
      health = health - q.top() + arr[i];
      q.pop();
      q.push(arr[i]);
      continue;
    }
    health += arr[i];
    q.push(arr[i]);
    ++current;
    res = max(res, current);
  }

  cout << res;

  return 0;
}
