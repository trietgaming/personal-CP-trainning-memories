#include <bits/stdc++.h>

using namespace std;

struct Bucket {
  int capacity;
  int currentMilk;
};

Bucket arr[3];

int main() {

  freopen("mixmilk.in", "r", stdin);
  freopen("mixmilk.out", "w", stdout);

  for (int i = 0; i < 3; ++i) {
    cin >> arr[i].capacity >> arr[i].currentMilk;
  }

  for (int i = 0; i < 100; ++i) {
    Bucket &toPour = arr[i%3], &beingPoured = arr[(i + 1) % 3];
    int temp = toPour.currentMilk;
    toPour.currentMilk = max(0, toPour.currentMilk - (beingPoured.capacity - beingPoured.currentMilk));
    beingPoured.currentMilk = min(beingPoured.capacity, beingPoured.currentMilk + temp);
  }

  for (int i = 0; i < 3; ++i) {
    cout << arr[i].currentMilk << "\n";
  }

  return 0;
}
