#include <bits/stdc++.h>
using namespace std;

int main() {
	// File input and output
	freopen ("sleepy.in","r",stdin);
	freopen ("sleepy.ans","w",stdout);

	// Take in size of array (n) and create a array to store the cow positions
	int n;
	cin >> n;
	int cows[n];

	// Take in the start positions of the cows and store them in the array
	for(int i = 0; i < n; i++)
	{
		cin >> cows[i];
	}

	// Compute x, the length of the increasing subarray at the end
	int x = 1;
	for(int i = n-2; i>-1 && cows[i] < cows[i+1]; i--)
		x++;

	// Print the answer, n-x
	printf("%d",n-x);
	fclose(stdout);
}
