#include <bits/stdc++.h>

using namespace std;

const string FNAME = "";

const int MAXN = 100;

void genTest() {

  ofstream inp("sleepy.in");
  int n = rand() % MAXN + 1;
  vector<int> arr;
  for (int i = 1; i <= n; ++i) {
    arr.push_back(i);
  }

  random_shuffle(arr.begin(), arr.end());

  inp << n << endl;
  for (auto i: arr) inp << i << " ";
  inp.close();

}

const int TESTS = 100;

int main() {
  srand(time(NULL));

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  for (int t = 0; t < TESTS; ++t) {
    genTest();
    system("sleepy_cow_sorting.exe");
    system("sleepy_cow_sorting_test.exe");
    if (system("fc sleepy.out sleepy.ans")) break;
  }


  return 0;
}


