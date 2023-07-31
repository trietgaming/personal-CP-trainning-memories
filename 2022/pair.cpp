#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream inp("pair.inp");
	int n, d;
	inp >> n >> d;
	long long arr[2000];
	for (int i = 0; i < n; ++i) inp >> arr[i];
	int dp[2000][50];
	int max = -1; 
	for (int i = 1; i < n; ++i) {
		long long temp = arr[i] + arr[i - 1];
		for (long long j = temp - d; j <= temp + d; ++j) {
			if (!dp[i-1][j]) dp[i-1][j] = 0;
			dp[i][j] = dp[i-1][j] + 1;
			if (dp[i][j] > max) max = dp[i][j];
		}
	}
	cout << max;
	inp.close();
	return 0;	
}
