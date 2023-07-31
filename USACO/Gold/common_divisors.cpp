#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "commondiv";
const int MAXN = 2*1e5, MAXX = 1e6;

bool calculated[MAXX + 1];
int appear_time[MAXX + 1], multiple_appear_time[MAXX + 1], largest_prime_divisible_by[MAXX + 1];
int arr[MAXN];

void sieve() {
  for (int i = 2; i <= MAXX; ++i) {
    if (largest_prime_divisible_by[i]) continue;
    for (int j = i; j <= MAXX; j += i) {
      largest_prime_divisible_by[j] = i;
    }
  }
}

vector<int> divisors;

void calc_divisors(int num) {
  divisors.clear();
  divisors.push_back(1);
  while (num > 1) {
    int cur_prime_exp = 1;
    int prime = largest_prime_divisible_by[num];
    int prev_len = divisors.size();
    while (num % prime == 0) {
      num /= prime;
      cur_prime_exp *= prime;
      for (int i = 0; i < prev_len; ++i) {
        divisors.push_back(cur_prime_exp * divisors[i]);
      }
    }
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

  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    ++appear_time[arr[i]];
  }

  for (int i = 0; i < n; ++i) {
    int x = arr[i];
    if (calculated[x]) continue;
    calculated[x] = true;
    calc_divisors(x);
    for (int i = 1; i < divisors.size(); ++i) {
      multiple_appear_time[divisors[i]] += appear_time[x];
    }
  }

  int res = 1;
  for (int x = 2; x <= MAXX; ++x) {
    if (multiple_appear_time[x] >= 2) res = x;
  }

  cout << res;

  return 0;
}


