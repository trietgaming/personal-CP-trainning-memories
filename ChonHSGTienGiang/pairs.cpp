#include <bits/stdc++.h>

using namespace std;

ifstream inp("PAIRS.inp");
int arr[200001];

void calc() {
  int n;
  inp >> n;
  for (int i = 1; i <= n; ++i) {
    inp >> arr[i];
  }
  int res = 0;

  for (int i = 1; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
        if (arr[i] * arr[j] == i + j) {
          cout << arr[i] << "*" << arr[j] << " = " << i << " + " << j << " | ";
          ++res;
        };
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
