#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "";
const int MAXN = 2*1e5;

int arr[MAXN + 1];

int main() {
//  ios_base::sync_with_stdio(false);
//  cout.tie(NULL);
//  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;

  stack<int> st;
  st.push(0);
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    while (arr[st.top()] >= arr[i]) {
      st.pop();
    }
    cout << st.top() << " ";
    st.push(i);
  }

  return 0;
}


