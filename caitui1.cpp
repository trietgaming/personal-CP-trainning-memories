#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct gold {
    ll weight;
    ll value;
};

bool goldCmp(gold &a, gold &b) {
    return a.weight < b.weight;
}

int main() {
    ll n;
    cin >> n;
    ll maxWeight;
    cin >> maxWeight;

    gold golds[40];
    for (ll i = 0; i < n; ++i) {
        cin >> golds[i].weight >> golds[i].value;
    }

    sort(golds, golds + n, goldCmp);

    map<ll, ll> mp;
    mp[0] = 0;
    for (ll i = 0; i < n; ++i)
      mp[golds[i].weight] = max(mp[golds[i].weight], golds[i].value);

    for (ll i = 1; i < n; ++i) {
        for (map<ll, ll>::iterator j = mp.begin(), e = mp.find(golds[i].weight); j != e; ++j) {
          int key = j->first + golds[i].weight;
          mp[key] = max(mp[key], golds[i].value + j->second);
        }
    }

    long long res = LLONG_MIN;

    for (map<ll, ll>::iterator i = mp.begin(); i != mp.end(); ++i) {
      if (i->first <= maxWeight)
        res = max(res, i->second);
    }

    cout << res;

    return 0;
}
