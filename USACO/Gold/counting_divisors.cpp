#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//const string FNAME = "";
const int MAX_X = 1e6;
int largest_prime_is_a_factor_of[(int) 1e6 + 1];

void sieve() {
  for (int i = 2; i <= MAX_X; ++i) {
    if (largest_prime_is_a_factor_of[i] != 0) continue;
    largest_prime_is_a_factor_of[i] = i;
    for (int j = i + i; j <= MAX_X; j += i)
      largest_prime_is_a_factor_of[j] = i;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);
  sieve();

  int n;
  cin >> n;
  while (n--) {
    int x, res = 1;
    cin >> x;
    while (x > 1) {
      int max_exponation = 0;
      int prime = largest_prime_is_a_factor_of[x];
      while (x % prime == 0) {
        x /= prime;
        ++max_exponation;
      }
      res *= max_exponation + 1;
    }
    cout << res << "\n";
  }

  return 0;
}

