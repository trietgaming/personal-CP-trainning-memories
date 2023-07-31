#include <bits/stdc++.h>

using namespace std;

const string FNAME = "traffic";

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int x, n;
  cin >> x >> n;

  set<int> trafficLights;
  multiset<int> lengths;
  trafficLights.insert(0);
  trafficLights.insert(x);
  lengths.insert(x);

  for (int i = 0; i < n; ++i) {
    int light;
    cin >> light;

    set<int>::iterator leftMostLight = trafficLights.upper_bound(light);
    set<int>::iterator rightMostLight = leftMostLight;
    leftMostLight--;
    int length = *rightMostLight - *leftMostLight;
//    cout << length << " ";
//    assert(lengths.find(length) != lengths.end());
    lengths.erase(lengths.find(length));

    trafficLights.insert(light);
    lengths.insert(light - *leftMostLight);
    lengths.insert(*rightMostLight - light);

//    for (auto m: lengths) {
//      cout << m << " ";
//    }

    set<int>::iterator largest = lengths.end(); --largest;
    cout << *largest << " ";
  }

  return 0;
}


