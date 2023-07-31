#include <bits/stdc++.h>

using namespace std;

const string FNAME = "";

int ranRange(int s, int e) {
  return s + (rand() % (e - s + 1));
}

const int numTest = 10;
const int maxN = 100000;

const string fName = "madeup";

void genInp() {
  ofstream inp(fName + ".in");
  int n = ranRange(1, maxN);
  inp << n << endl;
  for (int t= 0; t < 3; ++t) {
    for (int i = 0; i < n; ++i) {
      inp << ranRange(1, maxN) << " ";
    }
    inp << endl;
  }
  inp.close();
}

int main() {
  srand(time(NULL));

  for (int t = 0; t < numTest; ++t) {
    genInp();
    system("made_up.exe");
    system("made_up_test.exe");
    if (system("fc madeup.ans madeup.out")) break;
  }


  return 0;
}


