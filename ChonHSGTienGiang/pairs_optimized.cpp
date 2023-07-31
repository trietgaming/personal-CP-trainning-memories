#include <bits/stdc++.h>

using namespace std;

ifstream inp("PAIRS.inp");


int arr[200001];
int mp[400001];

void calc() {
  int n;
  int res = 0;
  inp >> n;
  memset(mp, -1, sizeof(mp));
  for (int i = 1; i <= n; ++i) {
    inp >> arr[i];
    mp[arr[i]] = i;
  }
  for (int i = 3, e = n*2; i < e; ++i) {
    for (int j = 1, ej = sqrt(i); j <= ej; ++j) {
      if (i % j != 0 || mp[j] == -1 || i-mp[j] == mp[j]) continue;
      if (arr[i-mp[j]] == i / j) {
        cout << j << "*" << i/j << " = " << mp[j] << " + " << i-mp[j] << " | ";
        ++res;
      }

    }
  }
  cout << "(" << res << ")" << endl;
}

int main() {


  int t;
  inp >> t;

  while (t--) {
    calc();
  }

  inp.close();

  return 0;
}
