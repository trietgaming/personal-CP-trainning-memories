#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> dint;

bool cmp(pair<int, dint> a, pair< int, dint> b) {
	return a.first < b.first;
}

int main() {
	
	ifstream inp("pair.inp");
	int n, d;
	inp >> n >> d;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) inp >> arr[i];
	sort(arr.begin(), arr.end());

	vector<pair<int, dint> > sums; 

	for (int i = 0; i < n; ++i) {
		for (int j = n - 1; j > i; --j) {
			pair<int, dint> p(arr[i] + arr[j] + d, dint(i, j));
			sums.push_back(p);
			if (d == 0) continue;
			p.first = arr[i] + arr[j];
			sums.push_back(p);
		}
	}
	
	int res = 0;
	
	stable_sort(sums.begin(), sums.end(), cmp);
	sums.push_back(pair<int, dint>(INT_MIN, dint(0, 0)));
	
	int check[2000];
	int id = sums[0].first, temp = 0;
	for (int i = 0, s = sums.size(); i < s; ++i) {
		int k = sums[i].second.first;
		int l = sums[i].second.second;
		if (check[k] != id && check[l] != id) {
			check[k] = check[l] = id;
			++temp;
		};
		if (sums[i].first != sums[i + 1].first) {
			res = max(res, temp);
			temp = 0;
			id = sums[i + 1].first;
		}
	}
	
	ofstream op("pair.out");
	
	op << res;
	
	inp.close();
  op.close();

	return 0;
}

