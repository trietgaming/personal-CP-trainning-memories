#include <bits/stdc++.h>

using namespace std;

int dp[300][300][300];
char matrix[300][300];
const int movesX[] = {0, 0, -1, 1};
const int movesY[] = {1, -1, 0, 0};

struct state {
  int row, col, pos;
  state(int r, int c, int p) {
    row = r;
    col = c;
    pos = p;
  }
};

int main() {
  memset(dp, -1, sizeof(dp));
	int rows, cols, strLength;
	cin >> rows >> cols >> strLength;
	string s;
	cin >> s;

	queue<state> q;

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cin >> matrix[i][j];
			if (matrix[i][j] == s[0]) {
        q.push(state(i, j, 0));
        dp[0][i][j] = 1;
			};
		}
	}

	while (!q.empty()) {
    state f = q.front();
    q.pop();
    if (f.pos == strLength-1) {
        cout << dp[f.pos][f.row][f.col];
        break;
    }
    for (int i = 0; i < 4; ++i) {
        int nextRow = f.row + movesX[i];
        int nextCol = f.col + movesY[i];
        int nextPos = f.pos;

        if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols)
          continue;
        if (matrix[nextRow][nextCol] == s[f.pos + 1]) {
          ++nextPos;
        }
        if (dp[nextPos][nextRow][nextCol] != -1) continue;
        q.push(state(nextRow, nextCol, nextPos));
        dp[nextPos][nextRow][nextCol] = dp[f.pos][f.row][f.col] + 1;
    }
	}
	return 0;
}
