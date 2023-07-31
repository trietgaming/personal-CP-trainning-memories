#include <bits/stdc++>

using namespace std;

typedef pair<int, int> pii;

int main() {
	
	ifstream inp("SSEQ.inp");
	
	int n;
	inp >> n;
	
	vector<pair<int, pii> > v;
	
	pair<int, pii> temp;
	for (int i = 0; i < n; ++i) {
		inp >> temp.second.first >> temp.second.second >> temp.first;
		v.push_back(temp);
	}
	
	for (int i = 0; i < n; ++i) {
		cout << v[i].second.first << v[i].second.second < v[i].first;
	}
	
	return 0;
}
