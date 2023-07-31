#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int arr[100001];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    int s; cin >> s;

    int i = 0, j = 0;
    int sum = arr[0];

    bool isNone = true;

    while (i < n) {
    		cout << i << endl;
        if (sum < s) {
            ++i; 
            sum += arr[i];
            continue;
        } 
        if (sum > s) {
            sum -= arr[j];
            ++j;
            continue;
        }
        isNone = false;
        for (int k = j; k <= i; ++k) {
            cout << arr[k] << " ";
        }
        break;
    }

    if (isNone) cout << -1;

    return 0;
}
