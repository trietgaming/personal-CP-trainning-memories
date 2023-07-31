#include <bits/stdc++.h>

using namespace std;

long long res = 0;

void merge(vector<int> &v, vector<int> &temp, int l, int mid, int r) {
	int i = l, k = l, j = mid + 1;
	while (i <= mid && j <= r) {
		if (v[i] >= v[j]) temp[k++] = v[i++];
		else temp[k++] = v[j++];
	}
	while (i <= mid) temp[k++] = v[i++];
	while (j <= r) temp[k++] = v[j++];
	for (int i = l; i <= r; ++i) v[i] = temp[i];
}

void mergeAndCount(vector<int> feq[], vector<int> &temp, int l, int r) {
	if (l >= r) return;
	int mid = l + (r - l) / 2;
	mergeAndCount(feq, temp, l, mid);
	mergeAndCount(feq, temp, mid + 1, r);
	int i = l, j = mid + 1;
	while (i <= mid && j <= r) {
		if (feq[0][i] > feq[1][j]) {
			res += r - j + 1;
			++i;
		} else ++j;
	}
	for (int i = 0; i <= 1; ++i) {
			for (int j = l; j <= r; ++j) {
				cout << feq[i][j] << " ";
			}
			cout << endl;
		}
	merge(feq[0], temp, l, mid, r);
	merge(feq[1], temp, l, mid, r);
}

void calc(vector<int> feq[]) {
	vector<int> temp(feq[0].size(), 0);
	mergeAndCount(feq, temp, 0, feq[0].size() - 1);
}

long long countOccurrencePairs(std::vector<int> a)
{
    int n = a.size();
    map<int, int> mp;
    vector<int> feq[2];
    for (int i = 0; i < n; ++i) {
    	feq[0].push_back(++mp[a[i]]);
		}
		mp.clear();
		feq[1] = vector<int>(n, 0);
		for (int i = n - 1; i >= 0; --i) {
    	feq[1][i] = ++mp[a[i]];
		}
		calc(feq);
		for (int i = 0; i <= 1; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << feq[i][j] << " ";
			}
			cout << endl;
		}
    return res;
}

int main() {
	
	int a[] = {2, 3, 3, 2, 1, 3, 2, 4, 3, 3};
	
	vector<int> arr(a, a + (sizeof(a) / sizeof(a[0])));
	
	cout << countOccurrencePairs(arr);
	
	return 0;
}
