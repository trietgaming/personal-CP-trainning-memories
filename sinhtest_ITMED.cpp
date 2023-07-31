#include <bits/stdc++.h>

using namespace std;

const string fileName = "ITMED";
const string inpext = ".inp";
const string outext = ".ans";

const int TESTS = 6;

int random(int l = 0, int r = RAND_MAX) {
  return l + rand() % (r - l + 1);
}

int main() {
  srand(time(NULL));

  ofstream inp(fileName + ".inp");
  for (int itest = 0; itest < TESTS; ++itest) {
    int n = random(3, 15);
    int k = random(1, n);
    vector<int> arr(n);

    inp << n << " ";
    inp << k;
    inp << endl;
    for (int i = 0; i < n; ++i) {
      arr[i] = random(-14, 20);
      inp << arr[i] << " ";
    }

    inp << endl;
  }
  inp.close();

  return 0;
}
