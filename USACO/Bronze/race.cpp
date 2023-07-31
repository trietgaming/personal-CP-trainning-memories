#include <bits/stdc++.h>

using namespace std;

const string FNAME = "race";
long long k;

long long sum1toN(long long n) {
  return (n*(n+1)/2);
}

long long sumRange(int s, int e) {
  if (e < s) return 0;
  return sum1toN(e) - sum1toN(s - 1);
}

bool canChangeSpeed(long long speed, long long lim, long long remain){
  return speed <= lim|| sumRange(lim + 1, speed - 1) < remain;
}

long long minTimeToRun(long long lim) {
  long long curTime = 0, remain = k, speed = 0;
  while (remain > 0) {
    if (canChangeSpeed(speed + 1, lim, remain - (speed + 1))) ++speed;
    else if (!canChangeSpeed(speed, lim, remain - speed)) --speed;
    remain -= speed;
    ++curTime;
  }
  return curTime;
}

int main() {

  freopen((FNAME + ".in").c_str(), "r", stdin);
  freopen((FNAME + ".out").c_str(), "w", stdout);

  int n;
  cin >> k >> n;
  long long lim;
  for (int i = 0; i < n; ++i) {
    cin >> lim;
    cout << minTimeToRun(lim) << endl;
  }

  return 0;
}


