#include <bits/stdc++.h>

using namespace std;

const string FNAME = "";

int main() {

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  ifstream ans("hoofball.expected"), sample("hoofball.sample");

  while (true) {
    int n;
    sample >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
      sample >> arr[i];
    }
    ofstream inp("hoofball.in");
    inp << n << endl;
    for (int i: arr) inp << i << " ";
    inp.close();

    int expected;
    ans >> expected;

    ofstream res("hoofball.ans");
    res << expected;
    res.close();

    system("hoofball.exe");
    if (system("fc hoofball.out hoofball.ans")) {
      break;
    }
    if (sample.eof()) break;
  }

  return 0;
}


