#include <bits/stdc++.h>

using namespace std;

const string FNAME = "sumKquery";

unordered_map<long long, bool> appear[5];
int arr[100000];

void process(unordered_map<long long, bool> &mp) {
    long long n, k, a;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    cout << "NO";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  long long Q, n, k, a;
  cin >> Q;
  for (int q = 0; q < Q; ++q) {
    process(appear[q]);
  }

  return 0;
}


