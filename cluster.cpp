#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

int cluster(vector<vector<int> > matrix)
{
    int res = 0;
    int cx[4] = {1, 0, -1, 0};
		int cy[4] = {0, 1, 0, -1};
    for (int i = 0, n = matrix.size(); i < n; i++) {
        for (int j = 0, m = matrix[i].size(); j < m; ++j) {
            if (matrix[i][j] != 1) continue;
            res++;
            queue<int> qx, qy;
            qy.push(i);
            qx.push(j);
						while(!qx.empty()) {
								int x = qx.front();
								int y = qy.front();
		            matrix[y][x] = 0;
		            for (int k = 0; k < 4; ++k) {
		                int tx = x + cx[k];
		                int ty = y + cy[k];
//		                cout << tx << " " << ty << endl;
			              if (tx < m && tx >= 0 && ty >= 0 && ty < n && matrix[ty][tx] == 1){
			                	qx.push(tx);
			                 	qy.push(ty);
										}		            
		             }
		            qx.pop();
		            qy.pop();
              
             }
          
        }
    }
    return res;
}

int main() {
	vector<vector<int> > test;
	ifstream inp("cluster.inp");
	vector<int> v;
	while (!inp.eof()) {
		int temp;
		inp >> temp;
		v.push_back(temp);
		if (inp.peek() == '\n' || inp.peek() == -1) {
			test.push_back(v);
			v = vector<int>();
		}
		cout << inp.peek() << " ";
	}
	inp.close();
	cout << endl;
	for (int i = 0, n = test.size(); i < n; i++) {
    for (int j = 0, m = test[i].size(); j < m; ++j) {
    	cout << test[i][j] << " ";
    }
    cout << endl;   
  }
	cout << "result" << cluster(test);
	return 0;
}

