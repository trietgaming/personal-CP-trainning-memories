#include <bits/stdc++.h>

using namespace std;

typedef map<int, vector<pair<int, int> > > mapSubArr;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int maxSubArray(vector<pair<int, int> > &subArrs) {
  int res = 1;
  sort(subArrs.begin(), subArrs.end(), cmp);
  pair<int, int> last = subArrs[0];
  for (int i = 1, n = subArrs.size(); i < n; ++i) {
  	if (subArrs[i].first > last.second) {
  		++res;
  		last = subArrs[i];
		}
	}
	for (int i = 0; i < subArrs.size(); ++i)
		cout << subArrs[i].first << " " << subArrs[i].second << endl;
  return res;
}

int numberOfSubArray(std::vector<int> arr)
{
    int n = arr.size();
    vector<int> prefixSum(1, arr[0]);
    for (int i = 1; i < n; ++i) {
        prefixSum.push_back(prefixSum.back() + arr[i]);
    }
    vector<vector<int> > matrix(1, prefixSum);
    for (int i = 1; i < n; ++i) {
        vector<int> temp(i, 0);
        int m = matrix[i - 1][i - 1];
        for (int j = i; j < n; ++j) {
            temp.push_back(matrix[i - 1][j] - m);
        }
        matrix.push_back(temp);
    }
    int m = matrix[0].size();
    mapSubArr mp;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < m; ++j) {
            mp[matrix[i][j]].push_back(pair<int, int>(i, j));
        }
    }
    int res = 1;
    for (mapSubArr::iterator i = mp.begin(); i != mp.end(); ++i) {     
			cout << "("<<i->first << ")" <<endl;
			cout << "_________________________"<<endl;
			res = max(res, maxSubArray(i->second));
    	cout << "_________________________"<<endl;
    }
    return res;
}

int main() {
	
	int a[] = {-7,-8,-15,13,-5,-7,-4,-5,-8,29,-3,-2,7,-12,3,-2,-9,4,24,1,-11,14,-2,-13,-15,-3,18,-1,4};
	vector<int> arr(a, a + (sizeof(a) / sizeof(a[0])));
	
	for (int i = 0; i < arr.size(); ++i) cout << arr[i] << " ";
	cout << endl;
	cout << numberOfSubArray(arr);
	
	return 0;
}
