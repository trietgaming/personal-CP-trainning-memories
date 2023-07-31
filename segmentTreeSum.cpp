#include<bits/stdc++.h>

using namespace std;

int n;

void update(vector<long long> &st, int pos, long long val) {
	for (st[pos += n] = val; pos > 1; pos >>= 1) {
		st[pos >> 1] = st[pos] + st[pos^1];		
	}
}

long long query(vector<long long> &st, int l, int r) {
	long long res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) res += st[l++];
		if (r&1) res += st[--r];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
	cin >> n;
	vector<long long> st(2*n, 0);
	int q; cin >> q;
	
	long long t, x, y;
	while (q--) {
		cin >> t >> x >> y;
		if (t == 1) {
			update(st, x - 1, y);
			continue;
		}
		cout << query(st, x - 1, y) << endl;
	}
	
	return 0;
}
