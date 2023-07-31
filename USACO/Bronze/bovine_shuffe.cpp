#include <bits/stdc++.h>

using namespace std;

string unshuffled[100], shuffled[100];
int pos[100];

int main() {

  freopen("shuffle.in", "r", stdin);
  freopen("shuffle.out", "w", stdout);

  int n;
  cin >> n;

  for (int i = 0, temp; i < n; ++i) {
    cin >> temp;
    pos[temp - 1] = i;
  }

  for (int i = 0; i < n; ++i) {
    cin >> unshuffled[i];
  }

  for (int sh = 0; sh < 3; ++sh) {
    for (int i = 0; i < n; ++i) {
      shuffled[pos[i]] = unshuffled[i];
    }
    for (int i = 0; i < n; ++i) {
      unshuffled[i] = shuffled[i];
    }
  }


  for (int i = 0; i < n; ++i) {
    cout << shuffled[i] << "\n";
  }

  return 0;
}
