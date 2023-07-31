#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const string FNAME = "jobschedule";
const ll MAXN = 100002, MAXM = 1000000;

struct Job {
  ll numJob, deadline;
  Job() {}
  Job(ll num, ll d) {
    numJob = num;
    deadline = d;
  }
};

struct cmp {
  bool operator() (const Job &a, const Job &b) {
    if (a.deadline == b.deadline) return a.numJob < b.numJob;
    return a.deadline > b.deadline;
  }
};

ll dayJobs[MAXN], tempDay[MAXN], iter[MAXN];
ll n, delays, m;
vector<ll> dayIndex[MAXN];

bool goodJob(ll machineNum) {
  priority_queue<Job, vector<Job>, cmp> q;
  for (ll i = 1; i <= n; ++i) {
    q.push(Job(dayJobs[i], i + delays));

    ll remain = machineNum - q.top().numJob;
    while (q.size() && remain >= 0) {
      q.pop();
      if (q.size()) remain -= q.top().numJob;
    }
    if (q.size() && remain < 0) {
      Job j = q.top();
      j.numJob = -remain;
      q.pop();
      q.push(j);
    }
  }

  return q.empty();
}

ll minMachine(ll l, ll r) {
  if (l == r) {
    goodJob(l);
    return l;
  }
  ll mid = (l + r) / 2;
  if (goodJob(mid)) return minMachine(l, mid);
  return minMachine(mid + 1, r);
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

//  freopen((FNAME + ".in").c_str(), "r", stdin);
//  freopen((FNAME + ".out").c_str(), "w", stdout);

  cin >> n >> delays >> m;

  for (ll i = 0; i < m; ++i) {
    ll day;
    cin >> day;
    ++dayJobs[day];
    dayIndex[day].push_back(i+1);
  }

  ll res = minMachine(1, 1000000);
  cout << res << endl;

  priority_queue<Job, vector<Job>, cmp> q;
  for (ll i = 1; i <= n; ++i) {
    q.push(Job(dayJobs[i], i + delays));

    ll remain = res - q.top().numJob;
    while (q.size() && remain >= 0) {
      for (ll i = 0; i < q.top().numJob; ++i) {
        cout << dayIndex[q.top().deadline - delays][iter[q.top().deadline - delays]++] << " ";
      }
      q.pop();
      if (q.size()) remain -= q.top().numJob;
    }
    if (q.size() && remain < 0) {
      if (q.top().numJob + remain) {
        for (ll i = 0; i < q.top().numJob + remain; ++i) {
          cout << dayIndex[q.top().deadline - delays][iter[q.top().deadline - delays]++] << " ";
        }
      }
      Job j = q.top();
      j.numJob = -remain;
      q.pop();
      q.push(j);
    }
    cout << 0 << "\n";
  }

  return 0;
}


