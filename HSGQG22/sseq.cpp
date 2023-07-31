#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

long long tree[MAXN << 1];
long long lazy[MAXN];
long long n;

void apply(int p, int val) {
  tree[p] += val
  lazy[p >> 1] += val;
}


int main() {

	ifstream inp("SSEQ.inp");
	inp >> n;



	ofstream out("SSEQ.out");

	out << res;
	inp.close();
	out.close();

	return 0;
}

