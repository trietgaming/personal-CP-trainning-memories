#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2, s = sqrt(n); i <= s; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

void recursive(int product, int& result, int current) {
	if (product / 10 == 0) {
		current *= 10;
		current += product;
		if (result == 0 || current < result) result = current;
		return;
	}
	for (int i = 2; i <= 9; ++i) {
		if (product % i == 0) {
			recursive(product / i, result, current * 10 + i);
		}
	}
}

int digitsProduct(int product) {
	if (product / 10 == 0) {
		return 10 + product;
	}
	if (isPrime(product)) return -1;
	int result = 0;
	recursive(product, result, 0);
	return result;
}

int main() {
	
	int n; cin >> n;
	
	cout << digitsProduct(n);
	
	return 0;
}
