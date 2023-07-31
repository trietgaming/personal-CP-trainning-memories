#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <fstream>

using namespace std;

typedef std::pair<int, int> point;

void printMatrix(std::vector<std::vector<int> > matrix) {
	const int n = matrix.size();
	for (int i = 0; i < n; ++i) {
      for (int j = 0, m = matrix[i].size(); j < m; ++j) {
      	cout << matrix[i][j] << " ";
    }
    cout << endl;
	}
}


int rotOrange(std::vector<std::vector<int> > matrix)
{
    int h[4] = {1, 0, -1, 0};
    int v[4] = {0, -1, 0, 1};
    int fresh = 0;
    int res = 0;
    const int n = matrix.size();
    queue<point> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0, m = matrix[i].size(); j < m; ++j) {
            int current = matrix[i][j];
            if (current == 1) fresh++;
            else if (current == 2) {
                queue<point> qt;
                point p(i, j);
                q.push(p);
            }
        }
    }
    while (true) {
    	queue<point> next;
    	while (!q.empty()) {
    		point p = q.front();
    		for (int i = 0; i < 4; ++i) {
    			point move(p.first + v[i],p.second + h[i]);
    			int y = move.first, x = move.second;
    			if (y < 0 || y >= n || x < 0 || x >= matrix[y].size() || matrix[y][x] != 1)
    				continue;
    			next.push(move);
    			matrix[y][x] = 2;
    			fresh--;
				}
				q.pop();
			}
			if (next.empty()) break;
			q = next;
			res++;
			printMatrix(matrix);
		}
    if (fresh != 0) return -1;
    return res;
}

int main() {
	vector<vector<int> > test;
	ifstream inp("rotOrange.inp");
	vector<int> v;
	while (!inp.eof()) {
		int temp;
		inp >> temp;
		v.push_back(temp);
		if (inp.peek() == '\n' || inp.peek() == -1) {
			test.push_back(v);
			v = vector<int>();
		}
	}
	printMatrix(test);
	cout << endl;
	inp.close();
	cout << rotOrange(test);
	return 0;
}
