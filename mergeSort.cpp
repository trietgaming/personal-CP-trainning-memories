#include <iostream>
#include <vector>

using namespace std;

void mergeSort(int arr[], int l, int r){
    int mid = l + (r - l) / 2;
    if (mid == l) {
        if (arr[l] > arr[r]) swap(arr[l], arr[r]);
        return;
    }
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    vector<int> arr1, arr2;
    for (int i = l; i <= mid; ++i) {
    	arr1.push_back(arr[i]);
		}
		for (int i = mid + 1; i <= r; ++i) {
			arr2.push_back(arr[i]);
		}
		int k = l, i = 0, j = 0;
		while (i < arr1.size() || j < arr2.size()) {
			if ((j >= arr2.size() || arr1[i] <= arr2[j]) && i < arr1.size()) {
				arr[k] = arr1[i];
				++i;
			} else {
				arr[k] = arr2[j];
				++j;
			}
			++k;
		}
}

int main() {
    int n = 6;
    int arr[100001] = {3, 6, -1, 70, 7, 0};
//    for (int i = 0; i < n; ++i) {
//        cin >> arr[i];
//    }
    mergeSort(arr, 0, n-1);
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}
