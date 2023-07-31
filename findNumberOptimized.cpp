#include <bits/stdc++.h>

using namespace std;

int sumDigits(long long n) {
	int res = 0;
	while (n > 0) {
		res += n % 10;
		n/= 10;
	}
	return res;
}

bool isDigitsOddAppear(long long n, int d) {
	vector<int> arr;
	while (n > 0) {
		arr.push_back(n % 10);
		if (arr.back() > d) return false;
		n/= 10;
	}
	vector<int> check(10, 0);
	for (int i = 0; i < arr.size(); ++i) {
		++check[arr[i]];
	}
	for (int i = 0; i < arr.size(); ++i) {
		if (check[arr[i]] % 2 == 0) continue;
		return false;
	}
	return true;
}

bool isValid(long long num, int s, int m, int d) {
	return sumDigits(num) == s && num % m == 0 && isDigitsOddAppear(num, d);
}

int main() {

	int s = 10, d = 1, m = 4;
//	cin >> s >> d >> m;
	if (s & 1 || ((m == 3 || m == 9) && s % m != 0)) {
		cout << -1;
		return 0;
	}
	long long length = ((s / 2) / d + ((s / 2) % d > 0)) * 2;
	cout << length << endl;
	long long i = 0;
	while (!isValid(i, s, m, d)) i+=m;
	cout << i;
	
	return 0;
}
