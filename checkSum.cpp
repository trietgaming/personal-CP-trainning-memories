#include <iostream>
#include <vector>

using namespace std;

bool checkSum(vector<int> arr, int sum){
   bool c[10000];
   for (int i = 0, size = arr.size(); i < size; ++i) {
       if (c[sum - arr[i]]) return true;
       c[arr[i]] = true;
   }
   return false;
}

int main() {
	int a[] = {1, 6,3, 4, 7};
	vector<int> arr(a, a + sizeof(a) / sizeof(a[0]));
	cout << checkSum(arr, 14);
	return 0;
}
