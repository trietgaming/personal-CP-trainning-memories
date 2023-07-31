#include <bits/stdc++.h>

using namespace std;

const string FNAME = "room";
const int MAXN = 200000;

struct Customer {
  int arrival, departure, ind;
};

//bool operator <(const Customer &a, const Customer &b) {
//  return a.arrival < b.arrival;
//}

Customer customers[MAXN];
int res[MAXN];
map<int, vector<Customer>> mapOfCustomers;

int main() {

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> n;


  for (int i = 0; i < n; ++i) {
    cin >> customers[i].arrival >> customers[i].departure;
    customers[i].ind = i;
    mapOfCustomers[customers[i].arrival].push_back(customers[i]);
  }

  int k = 0;
  while (!mapOfCustomers.empty()) {
    ++k;
    map<int, vector<Customer>>::iterator c = mapOfCustomers.begin();
    while (c != mapOfCustomers.end()) {
//        cout << c->second.ind << "\n";
      map<int, vector<Customer>>::iterator temp = mapOfCustomers.upper_bound(c->second.back().departure);
      res[c->second.back().ind] = k;
      c->second.pop_back();
      if(c->second.empty()) mapOfCustomers.erase(c);
      c = temp;
    }
  }

  cout << k << "\n";
  for (int i = 0; i < n; ++i) cout << res[i] << " ";

  return 0;
}


