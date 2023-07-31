#include <iostream>
using namespace std;

int main(){
	
	string s;
	int tu=1;
	getline(cin,s);
	for (int i =0;i<s.size();i++){
		if (s[i]==' ') tu++;
	}
	cout<<"so tu la : "<<tu;
	return 0;
}
