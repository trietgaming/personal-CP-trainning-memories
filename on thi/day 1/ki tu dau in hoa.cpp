#include <iostream>
using namespace std;

int main(){
	cout<<"Nhap vao mot xau: ";
	string goc;getline(cin,goc);
	if (goc[0]>='a' && goc[0]<='z') goc[0]-=32;
	for (int i=1;i<goc.size();i++){
		if (goc[i-1]==' ' && goc[i]>='a' && goc[i]<='z' ) goc[i]-=32;
		if (goc[i-1]!=' ' && goc[i]>='A' && goc[i]<='Z' ) goc[i]+=32;
	}
	cout<<"Xau da chuan hoa: "<<goc;
	
	return 0;
}
