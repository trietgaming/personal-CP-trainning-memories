#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

  int n; cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  vector<int> rep;

  for (int i = 0; i < n; ++i) {
    vector<int>::iterator lower = lower_bound(rep.begin(), rep.end(), arr[i]);
    if (lower == rep.end()) {
      rep.push_back(arr[i]);
      continue;
    }
    *lower = arr[i];
  }

  cout << rep.size();

  return 0;
}
