#include <bits/stdc++.h>

using namespace std;

const int MAXBITS = 2003;

struct score {
  vector<bool> bits;
  int right = 0;
  void add(int n) {
    if (bits[n]) bits[n++] = 0;
    while (bits[n]) {
      ++n;
    }
    bits[n] = 1;
    if (n > right) right = n;
  }
  score() {
    bits.resize(MAXBITS, 0);
  }
};

// 1 : smaller, 2: equal, 3: greater
int compare(score &a, score &b) {
  if (a.right < b.right) return 1;
  if (a.right > b.right) return 3;
  for (int i = a.right; i >= 0; --i) {
    if (a.bits[i] < b.bits[i]) return 1;
    if (a.bits[i] > b.bits[i]) return 3;
  }
  return 2;
}

struct contester {
  int pos;
  score s;
  contester(int i, score _s) {
    pos = i;
    s = _s;
  }
};

bool cmp(contester &a, contester &b) {
  int res = compare(a.s, b.s);
  return res == 1 || res == 2;
}

// char printbits(score s) {
//   for (int i = s.right; i >=0; --i) {
//     cout << s.bits[i];
//   }
//   return ' ';
// }

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//  score s, v;
//  s.add(2);
//  s.add(2);
//  v.add(3);
//  cout << s.right << " " << v.right << endl;
//  for (int i = s.right; i >= 0; --i) {
//    cout << s.bits[i];
//  }
//  cout<< endl;
//  for (int i =v.right; i >= 0; --i) {
//    cout << v.bits[i];
//  }cout<< endl;
//  cout << compare(s, v);

  int n;
  vector<int> a, p;

  // INPUT
  cin >> n;
  for (int i = 0, temp; i < n; ++i) {
    cin >> temp;
    p.push_back(temp);
  }
  for (int i = 0, temp; i < n; ++i) {
    cin >> temp;
    a.push_back(temp);
  }

  // PROCCESS
  vector<contester> contesters;
  for (int i = 0; i < n; ++i) {
    score s;
    s.add(p[i]);
    s.add(a[i]);
    contesters.push_back(contester(i, s));
  }

  pair<int, int> res[2000];

  sort(contesters.begin(), contesters.end(), cmp);

  for (int i = 0; i < n; ++i) {
    contester &c = contesters[i];
    score best = c.s;
    best.add(1);
    score worst = c.s;
    worst.add(n);
    int bestRank = 1;
    int worstRank = n;
    int rem = 0;
    for (int j = 0; j < n; ++j) {
      if (j == i) {
        ++rem;
        continue;
      };
      contester &t = contesters[j];
      score tbest = t.s;
      tbest.add(1 + j - rem);
      score tworst = t.s;
      tworst.add(n - j + rem);
      int cmpbest = compare(best, tworst);
      if (cmpbest == 3 || cmpbest == 2) ++bestRank;
      if (compare(worst, tbest) == 1) --worstRank;
    //   cout << t.pos << " "<< printbits(tworst) << printbits(best) << " | ";
    }
    res[c.pos] = pair<int, int>(bestRank, worstRank);
    cout << endl;
  }

  for (int i = 0; i < n; ++i) {
    cout << res[i].first << " " << res[i].second << endl;
  }

  return 0;
}
