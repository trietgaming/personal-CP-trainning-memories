#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int>& arr, int from = -1, int to = -1, bool isEndl = true) {
	for (int i = from == -1? 0: from, size = to == -1 ? arr.size(): to + 1; i < size; ++i) cout << arr[i] << " ";
	if (isEndl) cout << endl;
}

void quicksort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = arr[(left + right)/2];
    int lo = left, hi = right;
    printArr(arr, left, right, false); cout << "["<<pivot<<"]" << endl;
    while (lo < hi) {
        while (arr[lo] < pivot) ++lo;
        while (arr[hi] > pivot) --hi;
        if (lo > hi) break;
        swap(arr[lo], arr[hi]);
        ++lo; --hi;
    }
    cout << "(left: " << left << "; hi: " << hi << "; lo: " << lo << "; right: "<< right << ") ";
    printArr(arr, left, hi, false);
    cout << "|";
    printArr(arr, lo, right);
    quicksort(arr, left, hi);
    quicksort(arr, lo, right);
}


int main() {
	int a[] = {5,4,3,2,2,2,4,9,8,7,7,7};
	std::vector<int> arr(a, a + sizeof(a) / sizeof(a[0]));
	printArr(arr);
	quicksort(arr, 0, arr.size() - 1);
	printArr(arr);
	return 0;
}
