#include <bits/stdc++.h>

using namespace std;

const int n = 10;

// Bucket 11th maybe previous bucket left from another barn
int buckets[2][20];
bool took[2][20];
unordered_set<int> res;

void backtrack(int gone, int current, bool isCurrentMovingFromB2toB1 = false) {
  if (gone == 4) {
    res.insert(current);
    return;
  }
  for (int i = 0; i < n; ++i) {
    if (took[isCurrentMovingFromB2toB1][i]) continue;
    took[isCurrentMovingFromB2toB1][i] = true;
    took[!isCurrentMovingFromB2toB1][i + n] = false;
    backtrack(gone + 1, isCurrentMovingFromB2toB1? current + buckets[isCurrentMovingFromB2toB1][i]: current - buckets[isCurrentMovingFromB2toB1][i], !isCurrentMovingFromB2toB1);
    took[isCurrentMovingFromB2toB1][i] = false;
    took[!isCurrentMovingFromB2toB1][i + n] = true;
  }
  for (int i = n; i < 2*n; ++i) {
    if (took[isCurrentMovingFromB2toB1][i]) continue;
    took[isCurrentMovingFromB2toB1][i] = true;
    took[!isCurrentMovingFromB2toB1][i - n] = false;
    backtrack(gone + 1, isCurrentMovingFromB2toB1? current + buckets[isCurrentMovingFromB2toB1][i]: current - buckets[isCurrentMovingFromB2toB1][i], !isCurrentMovingFromB2toB1);
    took[isCurrentMovingFromB2toB1][i] = false;
    took[!isCurrentMovingFromB2toB1][i - n] = true;
  }
}

int main() {

  freopen("backforth.in", "r", stdin);
  freopen("backforth.out", "w", stdout);

  for (int b = 0; b < 2; ++b) {
    for (int i = 0; i < n; ++i) {
      cin >> buckets[b][i];
    }
  }

  for (int i = n; i < 2*n; ++i){
    buckets[0][i] = buckets[1][i - n];
    buckets[1][i] = buckets[0][i - n];
    took[0][i] = true;
    took[1][i] = true;
  }

  backtrack(0, 1000);
//
//  for (int m: res) cout << m << " ";
  cout << res.size();

  return 0;
}
