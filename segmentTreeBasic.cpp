#include <bits/stdc++.h>

using namespace std;

int n;

void build(vector<int> &st) {
	for (int i = n - 1; i >= 0; --i) {
		st[i] = max(st[i << 1], st[i << 1 | 1]);
	}
}

void update(vector<int> &st, int &i, int &val) {
	for (st[i += n] = val; i > 1; i >>= 1) st[i >> 1] = max(st[i], st[i^1]);
}

int get(vector<int> &st, int &l, int &r) {
	int res = INT_MIN;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) res = max(res, st[l++]);
		if (r&1) res = max(res, st[--r]); 
	}
	return res;
} 

int main() {
	
	cin.tie(NULL); 
	ios_base::sync_with_stdio(false);
	cin >> n;
	
	vector<int> arr(2 * n, INT_MIN);
	
	for (int i = 0, temp; i < n; ++i) {
		cin >> temp;
		arr[i + n] = temp;
	}
	
	build(arr);
	
	int q;
	cin >> q;
	
	vector<int> outs;
	int type, x, y;
	while (q--) {
    cin >> type >> x >> y;
    if (type == 1) update(arr, --x, y);
    else cout << get(arr, --x, y) << '\n';
  }
	
	return 0;
}
