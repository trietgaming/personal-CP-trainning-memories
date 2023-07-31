#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int main() {
	ifstream inp("setvector.inp");
	int n, m;
	inp >> n >> m;
	vector<vector<int> > arr;
	for (int i = 0; i < n; ++i) {
		arr.push_back(vector<int>());
	  for (int j = 0; j < m; ++j) {
			int temp;
	    inp >> temp;
	    arr[i].push_back(temp);
		}	
	}
	
	set<vector<int> > s(arr.begin(), arr.end());
	
	for (set<vector<int> >::iterator i = s.begin(); i != s.end(); ++i) {
		vector<int> v = *i;
		for (vector<int>::iterator j = v.begin(); j != v.end(); ++j) {
			cout << *j << " ";
		}
		cout << endl;
	}
	
	inp.close();
	return 0;
}
