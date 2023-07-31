#include <iostream>
using namespace std;

void printResult(bool result) {
    if (result) cout << "YES";
    else cout << "NO";
}

int main() {
    int n; cin >> n;
    int arr[1000];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    };
    bool result = true;
    if (n <= 2) {
        printResult(result);
        return 0;
    }
    for (int i = 2; i < n; ++i) {
        if ((arr[i - 1] - arr[i - 2]) * (arr[i] - arr[i - 1]) < 0) {
            result = false;
            break;
        };
    }
    printResult(result);
}
