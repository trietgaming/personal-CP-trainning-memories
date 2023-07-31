#include <bits/stdc++.h>

using namespace std;

int main() {

  int k, w;
  long long toPay, budget;

  cin >> k >> budget >> w;

  toPay = (long long) k * (w*(w+1)/2);

  cout << max(toPay - budget, (long long) 0);

  return 0;
}
