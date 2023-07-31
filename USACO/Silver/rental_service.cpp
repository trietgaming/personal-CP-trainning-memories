#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "rental";
const ll MAXLIM = 100010;

struct Store {
  ll needed, pricePerGallon;
};

ll cows[MAXLIM], rentPrices[MAXLIM];
// max profit when rent x cows = rentProfit[x];
ll rentProfitAt[MAXLIM + 1];
Store stores[MAXLIM];

int cowNum, storeNum, rentNum;
int currentCowToBeMilked = 0, currentStoreToSellTo = 0;

bool cmpStore(const Store &a, const Store &b) {
  return a.pricePerGallon > b.pricePerGallon;
}

bool decCmp(const ll &a, const ll &b) {
  return a > b;
}

// Milk the highest milk production cow then sell to the highest cent/gallon store and rent all remain cow
ll milkProfit = 0;
ll milking() {
  ll gallonsToSell = cows[currentCowToBeMilked++];

  while (gallonsToSell > 0 && currentStoreToSellTo < storeNum) {
    Store &s = stores[currentStoreToSellTo];
    ll sellAmount = min(gallonsToSell, s.needed);
    milkProfit += sellAmount * s.pricePerGallon;
    s.needed -= sellAmount;
    gallonsToSell -= sellAmount;
    if (s.needed == 0) ++currentStoreToSellTo;
  }

  return milkProfit + rentProfitAt[cowNum - currentCowToBeMilked];
}

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> cowNum >> storeNum >> rentNum;

  for (int i = 0; i < cowNum; ++i) {
    cin >> cows[i];
  }

  for (int i = 0; i < storeNum; ++i) {
    cin >> stores[i].needed >> stores[i].pricePerGallon;
  }

  for (int i = 0; i < rentNum; ++i) {
    cin >> rentPrices[i];
  }

  sort(cows, cows + cowNum, decCmp);
  sort(stores, stores + storeNum, cmpStore);
  sort(rentPrices, rentPrices + rentNum, decCmp);

  // Rent first, then compare profit between renting and milking
  for (int i = 0, e = min(cowNum, rentNum); i < e; ++i) {
    rentProfitAt[i + 1] = rentProfitAt[i] + rentPrices[i];
  }
  for (int i = min(cowNum, rentNum) + 1; i <= max(cowNum, rentNum); ++i) {
    rentProfitAt[i] = rentProfitAt[i-1];
  }
  ll result = rentProfitAt[min(cowNum, rentNum)];

  // Milk until profit is less than before
  while (currentCowToBeMilked < cowNum && currentStoreToSellTo < storeNum) {
    result = max(result, milking());
  }

  cout << result;

  return 0;
}


