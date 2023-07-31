#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    string temp;
    long long res, base;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        res = 0;
        base = 1;
        for (int j = temp.length() - 1; j >= 0; --j) {
            if (temp[j] == '1') res+= base;
            base *= 2;
        }
        cout << res << endl;
    }
}
