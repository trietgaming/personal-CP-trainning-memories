#include <bits/stdc++.h>

using namespace std;

const int NUMTEST = 10;
const int NRANGE = 100;
const int MAXARRI = 1000;

const string FILE_NAME = "balancing";

int randomRange(int s, int e) {
  return s + (rand() % (e - s + 1));
}

int main() {
    srand(time(NULL));

    for (int t = 0; t < NUMTEST; ++t) {
      ofstream inpFile("balancing.in");
      int n = randomRange(1, NRANGE);
      inpFile << n << endl;
      cout << n << endl;
      for (int i = 0; i < n; ++i) {
          int x = randomRange(1, MAXARRI), y = randomRange(1, MAXARRI);
        while (x % 2 == 0) x = randomRange(1, MAXARRI);
        while (y % 2 == 0) y = randomRange(1, MAXARRI);
        inpFile << x << " " << y << endl;
        cout  << x << " " << y << endl;;
      }
      inpFile << EOF;
      inpFile.close();
      cout << endl;

      system("load_balancing.exe");
      system("load_balancing_test.exe");

      system(("fc " + FILE_NAME + ".out " + FILE_NAME + ".ans").c_str());
      cout << endl;

    }
}

