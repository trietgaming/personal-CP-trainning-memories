#include <bits/stdc++.h>

using namespace std;

int field[2000][2000];
int moveX[256], moveY[256];


int main() {
        
    freopen("mowing.in","r",stdin);
    freopen("mowing.out","w",stdout);
        
    moveX['W'] = -1; moveY['W'] = 0;
    moveX['E'] = 1; moveY['E'] = 0;
    moveX['N'] = 0; moveY['N'] = 1;
    moveX['S'] = 0; moveY['S'] = -1;
    int n;
    cin >> n;
    
    int curX = 1000, curY = 1000, curT = 0;
    int res = INT_MAX;
    
    for (int i = 0; i < n; ++i) {
        int mx, my, t;
        char dir;
        cin >> dir >> t;
        mx = moveX[dir]; my = moveY[dir];
        for (; t > 0; --t, ++curT) {
            curX += mx; curY += my;
            if (field[curX][curY]) {
                res = min(res, curT - field[curX][curY]);
            }
            field[curX][curY] = curT;
        }
    }
    if (res == INT_MAX) res = -1;
    cout << res;
    
    return 0;
}