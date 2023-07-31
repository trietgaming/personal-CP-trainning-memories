#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n; cin >> n;
	vector<long long> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	vector<bool> thieves(n+1, true);
	thieves[0] = thieves[1] = false;
	vector<int> primes;
	for (int i = 2; i <= n; ++i) {
		if (!thieves[i]) continue;
		for (int j = i + i; j <= n; j += i) thieves[j] = false;
		primes.push_back(i);
	} 
	vector<long long> dp(n, 0);
	vector<long long> prefixSums(1, arr[0]);
	for (int i = 1; i < n; ++i) prefixSums.push_back(prefixSums.back() + arr[i]);
	dp[primes[0]] = arr[primes[0] - 1];
	long long res = dp[primes[0]];
	for (int i = 1; i < primes.size(); ++i) {
		dp[primes[i]] = 
			max(arr[primes[i] - 1], 
			dp[primes[i - 1]] + prefixSums[primes[i] - 1] - prefixSums[primes[i - 1] - 1]);
		res = max(res, dp[primes[i]]);
	}
	cout << res;
	
	return 0;
}

