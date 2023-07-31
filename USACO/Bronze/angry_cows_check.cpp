#include <bits/stdc++.h>

using namespace std;

const string FNAME = "angry";
const int NUMTEST = 10;
const int n = 10;
const int maxEl = 30;

int ranRange(int s, int e) {
  return s + (rand() % (e - s + 1));
}

void genIn() {
  ofstream inp(FNAME + ".in");
  int tN = ranRange(1, n);
  inp << tN << endl;
  unordered_set<int> s;
  while (s.size() < tN) {
    int e = ranRange(1, maxEl);
    if (s.count(e)) continue;
    s.insert(e);
    inp << e << " ";
  }
  inp.close();
}

int main() {

  srand(time(NULL));
//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  for (int i = 0; i < NUMTEST; ++i) {
    genIn();
    system("angry_cows.exe");
    system("angry_cows_test.exe");
    if (system(("fc " + FNAME + ".out " + FNAME + ".ans").c_str())) {
      break;
    };
  }

  return 0;
}


